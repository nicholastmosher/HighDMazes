cc = $(shell which 'g++')

all:
	$(cc) -o main Main.cpp Maze.cpp Cell.cpp

tests:
	$(cc) -o test Main.cpp Maze.cpp Cell.cpp
	valgrind ./test
