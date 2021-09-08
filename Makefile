# the compiler: gcc for C program, define as g++ for C++
CC= g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CXXFLAGS= -std=c++11 -g -Wall

OBJECTS = param.o parse.o 
HEADERS := $(shell find . -path ./test -prune -o -name "*.hpp" -print)

myshell: myshell.o $(OBJECTS)
	$(CC) $(CXXFLAGS) -o $@ $^

$(OBJECTS): $(HEADERS)

testBuild: $(OBJECTS)
	$(CC) $(CXXFLAGS) -Itest/catch -o test/TestCase $(OBJECTS) test/TestCase.cpp

test: clean testBuild
	test/TestCase --success

clean:
	$(RM) *.o *.gch core myshell
