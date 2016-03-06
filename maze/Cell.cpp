#include "Cell.h"

Cell::Cell (int numDims, int* coords) {
	numDimensions = numDims;
	const int maxWalls = 2 * numDimensions;
	walls = (bool *) malloc(sizeof(bool) * maxWalls);

	for(int i = 0; i < maxWalls; ++i) {
		walls[i] = 1;
	}

	coordinates = coords;
}

Cell::~Cell() {
	free(walls);
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

bool Cell::isAdjacentInDimension(Cell *cell, int dimension) {

}

void Cell::setEllerSet(int set) {
	ellerSet = (set < 0 ? 0 : set);
}

int Cell::getEllerSet() {
	return ellerSet;
}

int* Cell::getCoordinates() {
	return coordinates;
}

bool* Cell::getWalls() {
	return walls;
}
