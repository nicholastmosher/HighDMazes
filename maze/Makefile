cc = $(shell which 'g++')

all:
	$(cc) -o main Maze.cpp Cell.cpp

tests:
	$(cc) -o test Maze.cpp Cell.cpp
	valgrind ./test
