include Makefile.h

default: all
all:: test_interrupted test_itoken test_jthread1 test_jthread2 test_cv
all::
	@echo ""
	@echo "Testcases:"
	@echo "  test_interrupted"
	@echo "  test_itoken"
	@echo "  test_jthread1"
	@echo "  test_jthread2"
	@echo "  test_cv"

test_interrupted: interrupted.hpp test_interrupted.cpp Makefile
	$(CXX17) $(CXXFLAGS17) $(INCLUDES) test_interrupted.cpp $(LDFLAGS17) -o $@17raw.exe
	echo PATH=\"$(PATH17)/bin:$$PATH\" ./$@17raw.exe '$$*' > $@17.exe
	echo PATH=\"$(PATH17)/bin:$$PATH\" ./$@17raw.exe '$$*' > $@.exe
	echo "- OK:  $@ and $@17  call  $@17raw.exe"

test_itoken: jthread_fwd.hpp interrupted.hpp interrupt_token.hpp condition_variable2.hpp test_itoken.cpp Makefile
	$(CXX17) $(CXXFLAGS17) $(INCLUDES) test_itoken.cpp $(LDFLAGS17) -o $@17raw.exe
	echo PATH=\"$(PATH17)/bin:$$PATH\" ./$@17raw.exe '$$*' > $@17.exe
	echo PATH=\"$(PATH17)/bin:$$PATH\" ./$@17raw.exe '$$*' > $@.exe
	echo "- OK:  $@ and $@17  call  $@17raw.exe"

test_jthread1: jthread_fwd.hpp interrupted.hpp interrupt_token.hpp condition_variable2.hpp jthread.hpp test_jthread1.cpp Makefile
	$(CXX17) $(CXXFLAGS17) $(INCLUDES) test_jthread1.cpp $(LDFLAGS17) -o $@17raw.exe
	echo PATH=\"$(PATH17)/bin:$$PATH\" ./$@17raw.exe '$$*' > $@17.exe
	echo PATH=\"$(PATH17)/bin:$$PATH\" ./$@17raw.exe '$$*' > $@.exe
	echo "- OK:  $@ and $@17  call  $@17raw.exe"

test_jthread2: jthread_fwd.hpp interrupted.hpp interrupt_token.hpp condition_variable2.hpp jthread.hpp test_jthread2.cpp Makefile
	$(CXX17) $(CXXFLAGS17) $(INCLUDES) test_jthread2.cpp $(LDFLAGS17) -o $@17raw.exe
	echo PATH=\"$(PATH17)/bin:$$PATH\" ./$@17raw.exe '$$*' > $@17.exe
	echo PATH=\"$(PATH17)/bin:$$PATH\" ./$@17raw.exe '$$*' > $@.exe
	echo "- OK:  $@ and $@17  call  $@17raw.exe"

test_cv: jthread_fwd.hpp interrupted.hpp interrupt_token.hpp jthread.hpp condition_variable2.hpp test_cv.cpp Makefile
	$(CXX17) $(CXXFLAGS17) $(INCLUDES) test_cv.cpp $(LDFLAGS17) -o $@17raw.exe
	echo PATH=\"$(PATH17)/bin:$$PATH\" ./$@17raw.exe '$$*' > $@17.exe
	echo PATH=\"$(PATH17)/bin:$$PATH\" ./$@17raw.exe '$$*' > $@.exe
	echo "- OK:  $@ and $@17  call  $@17raw.exe"

jthread.clang: jthread.hpp jthread.cpp itoken.hpp iwait.hpp Makefile
	$(CXXCLANG) $(CXXFLAGSCLANG) -std=c++1z $(INCLUDES) jthread.cpp $(LDFLAGSCLANG) -o $@clangraw.exe
	echo PATH=\"$(PATH17)/bin:$$PATH\" ./$@clangraw.exe '$$*' > $@clang.exe
	echo PATH=\"$(PATH17)/bin:$$PATH\" ./$@clangraw.exe '$$*' > $@.exe
	echo "- OK:  $@ and $@17  call  $@clangraw.exe"

