FILES :=                              \
    .travis.yml                       \
    html                              \


CXX        := g++-4.8
CXXFLAGS   := -pedantic -std=c++11 -Wall
LDFLAGS    := -lgtest -lgtest_main -pthread
GCOV       := gcov-4.8
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
VALGRIND   := valgrind

check:
	@not_found=0;                                 \
    for i in $(FILES);                            \
    do                                            \
        if [ -e $$i ];                            \
        then                                      \
            echo "$$i found";                     \
        else                                      \
            echo "$$i NOT FOUND";                 \
            not_found=`expr "$$not_found" + "1"`; \
        fi                                        \
    done;                                         \
    if [ $$not_found -ne 0 ];                     \
    then                                          \
        echo "$$not_found failures";              \
        exit 1;                                   \
    fi;                                           \
    echo "success";

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.tmp

config:
	git config -l

scrub:
	make clean
	rm -f  Life.log
	rm -rf life-tests
	rm -rf html
	rm -rf latex

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: RunDarwin.tmp TestDarwin.tmp

life-tests:
	git clone https://github.com/cs371p-fall-2015/life-tests.git

html: Doxyfile Darwin.h Darwin.c++ RunDarwin.c++ TestDarwin.c++
	doxygen Doxyfile

Darwin.log:
	git log > Darwin.log

Doxyfile:
	doxygen -g

RunLife: Life.h Life.c++ Cell.c++ RunLife.c++
	$(CXX) $(CXXFLAGS) Life.h Life.c++ Cell.c++ RunLife.c++ -o RunLife

RunLife.tmp: RunLife
	./RunLife < RunLife.in > RunLife.tmp
#	diff RunDarwin.tmp RunDarwin.out

TestLife: Life.h Life.c++ TestLife.c++ Cell.h Cell.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Life.h Life.c++ TestLife.c++ Cell.h Cell.c++ -o TestLife $(LDFLAGS)

TestDarwin.tmp: TestDarwin
	$(VALGRIND) ./TestDarwin                                       >  TestDarwin.tmp 2>&1
	$(GCOV) -b Darwin.c++     | grep -A 5 "File 'Darwin.c++'"     >> TestDarwin.tmp
	$(GCOV) -b TestDarwin.c++ | grep -A 5 "File 'TestDarwin.c++'" >> TestDarwin.tmp
	cat TestDarwin.tmp
