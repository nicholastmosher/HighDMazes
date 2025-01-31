#include "UnrealProject.h"
#include "Cell.h"

Cell::Cell (int numDimensions) {
	const int maxWalls = 2 * numDimensions;
	walls = (bool *) malloc(sizeof(bool) * maxWalls);
	
	for(int i = 0; i < maxWalls; ++i) {
		walls[i] = 1;
	}
}

void Cell::createWall (int wallIndex) {
	walls[wallIndex] = 1;
}

void Cell::deleteWall (int wallIndex) {
	walls[wallIndex] = 0;
}

bool Cell::isWall (int dimension, bool side) {
	int index = 2 * dimension + side;
	return walls[index];
}

bool *Cell::getWalls() {
	return walls;
}
