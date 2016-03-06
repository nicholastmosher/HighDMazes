cc = $(shell which 'g++')

all:
	$(cc) -o main Main.cpp Maze.cpp Cell.cpp Generation.cpp test/Test.cpp

tests: clean
	$(cc) -o tests Main.cpp Maze.cpp Cell.cpp Generation.cpp test/Test.cpp
	valgrind ./tests

clean:
	rm main tests
