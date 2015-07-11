ifeq ($(shell uname), Darwin)
    CXX       := g++
    CXXVER    := --version 2>&1 | grep c++
    GTESTVER  := head -1 /usr/local/src/gtest-1.7.0/CHANGES
    GCOV      := gcov
    GCOVFLAGS := -fprofile-arcs -ftest-coverage
    GCOVVER   := -version | grep version
    BOOST     := /usr/local/src/boost_1_57_0/boost
    LDFLAGS   := -lgtest_main
    VALGRIND  :=
else ifeq ($(CXX), clang++)
    CXXVER    := --version 2>&1 | grep clang
    GTESTVER  := dpkg -l libgtest-dev | grep libgtest
    GCOV      := gcov-4.6
    GCOVFLAGS := --coverage
    GCOVVER   := -v | grep gcov
    BOOST     := /usr/include/boost
    LDFLAGS   := -lgtest -lgtest_main -pthread
    VALGRIND  := valgrind
else
    CXX       := g++-4.8
    CXXVER    := --version 2>&1 | grep g++
    GTESTVER  := dpkg -l libgtest-dev | grep libgtest
    GCOV      := gcov-4.8
    GCOVFLAGS := -fprofile-arcs -ftest-coverage
    GCOVVER   := -v | grep gcov
    BOOST     := /usr/include/boost
    LDFLAGS   := -lgtest -lgtest_main -pthread
    VALGRIND  := valgrind
endif

CXXFLAGS := -pedantic -std=c++11 -Wall

.PRECIOUS: %.app

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f TestDeque

test: TestDeque.out

html: Doxyfile Deque.h TestDeque.c++
	doxygen Doxyfile

deque.log:
	git log > deque.log

deque-tests:
	git clone https://github.com/cs378-summer-2015/deque-tests.git

Doxyfile:
	doxygen -g

TestDeque: Deque.h TestDeque.c++
	$(CXX) $(GCOVFLAGS) $(CXXFLAGS) TestDeque.c++ -o TestDeque $(LDFLAGS)

TestDeque.out: TestDeque
	./TestDeque
	$(VALGRIND) ./TestDeque  >  TestDeque.out 2>&1
	$(GCOV) -b Deque.h       >> TestDeque.out
	$(GCOV) -b TestDeque.c++ >> TestDeque.out
	cat TestDeque.out
