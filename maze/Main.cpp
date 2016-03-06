#include "Maze.h"

int main(int argc, char *argv[]) {

	//If the program name contains the word "test", run the test suite.
	if(strstr(argv[0], "test")) return test();

    //int dimensions[3] = {3,4,5};
    //Maze *m = new Maze(3, dimensions);

	return 0;
}
