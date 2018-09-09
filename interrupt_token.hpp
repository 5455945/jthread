#ifndef INTERRUPT_TOKEN_HPP
#define INTERRUPT_TOKEN_HPP

//*****************************************************************************
// forward declarations are in separate header due to cyclic type dependencies:
//*****************************************************************************
#include "jthread_fwd.hpp"


//*****************************************************************************
//* implementation of new this_thread API for interrupts:
//*****************************************************************************
#include "interrupted.hpp"
#include <cassert>
#include <iostream> // in case we enable the debug output

namespace std {

void interrupt_token::throw_if_interrupted() const
{
  if (_ip && _ip->interrupted.load()) {
    throw ::std::interrupted();
  }
}

bool interrupt_token::interrupt()
{
  //std::cout.put('I').flush();
  if (!valid()) return false;
  auto wasInterrupted = _ip->interrupted.exchange(true);
  if (!wasInterrupted) {
    ::std::scoped_lock lg{_ip->cvMutex};  // might throw
    for (const auto& cvPtr : _ip->cvPtrs) {
      cvPtr->notify_all();
    }
  }
  //std::cout.put('i').flush();
  return wasInterrupted;
}

bool interrupt_token::registerCV(condition_variable2* cvPtr) {
  //std::cout.put('R').flush();
  if (!valid()) return false;
  {
    std::scoped_lock lg{_ip->cvMutex};
    _ip->cvPtrs.push_front(cvPtr);  // might throw
  }
  //std::cout.put('r').flush();
  return _ip->interrupted.load();
}

bool interrupt_token::unregisterCV(condition_variable2* cvPtr) {
  //std::cout.put('U').flush();
  if (!valid()) return false;
  {
    std::scoped_lock lg{_ip->cvMutex};
    // remove the FIRST found cv
    for (auto pos = _ip->cvPtrs.begin(); pos != _ip->cvPtrs.end(); ++pos) {
      if (*pos == cvPtr) {
        _ip->cvPtrs.erase(pos);
        break;
      }
    }
  }
  //std::cout.put('u').flush();
  return _ip->interrupted.load();
}


} // namespace std

#endif // INTERRUPT_TOKEN_HPP
