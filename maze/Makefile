cc = $(shell which 'g++')

all:
	$(cc) -o main Main.cpp Maze.cpp Cell.cpp Generation.cpp test/Test.cpp

tests: clean
	$(cc) -o tests Main.cpp Maze.cpp Cell.cpp Generation.cpp test/Test.cpp
	valgrind --leak-check=full ./tests

clean:
	rm -f main tests
