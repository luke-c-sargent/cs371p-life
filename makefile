FILES :=                              \
    .travis.yml                       \
    html                              \

CEEPEEPEES := \
	Life.h AbstractCell.h Cell.h FredkinCell.h ConwayCell.h \
	FredkinCell.c++ ConwayCell.c++ Cell.c++

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
	rm -f TestLife
	rm -f RunLife

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

RunLife: Life.h Life.c++ Cell.h Cell.c++ AbstractCell.h FredkinCell.h FredkinCell.c++ ConwayCell.h ConwayCell.c++ RunLife.c++
	$(CXX) $(CXXFLAGS) Life.h Life.c++ Cell.h Cell.c++ AbstractCell.h FredkinCell.h FredkinCell.c++ ConwayCell.h ConwayCell.c++ RunLife.c++ -o RunLife

RunLife.tmp: RunLife
	./RunLife < RunLife.in > RunLife.tmp
#	diff RunDarwin.tmp RunDarwin.out

TestLife:
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) $(CEEPEEPEES) TestLife.c++ -o TestLife $(LDFLAGS)

TestLife.tmp: TestLife
	$(VALGRIND) ./TestLife                                       >  TestLife.tmp 2>&1
	$(GCOV) -b TestLife.c++     | grep -A 5 "File 'Life.h'"     >> TestLife.tmp
	$(GCOV) -b TestLife.c++ | grep -A 5 "File 'TestLife.c++'" >> TestLife.tmp
	cat TestLife.tmp
