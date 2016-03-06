#include "Maze.h"
#include "Generation.h"

/**
 * Constructs a new maze with the given number of dimensions, with
 * the specified size for each dimension.
 */
Maze::Maze(int numDimensions, int* dimensionSizes) {
	
	hackInit();

	//Initialize the number of dimensions and the size of each dimension.
/*	numDimensions = numDimensions;
	dimensionSize = (int *) malloc(sizeof(int) * numDimensions);
	numCells = 1;

	//Copy each dimension size into the local array.
	for(int i = 0; i < numDimensions; ++i) {
		dimensionSize[i] = dimensionSizes[i];
		numCells *= dimensionSize[i];
	}

	//TODO construct coordinates via polynomial vector
	int* dimensionMultipliers = (int *) malloc(sizeof(int) * numDimensions);
	int currentMultiplier = 1;
	for (int i = numDimensions; i >= 0; --i) {
		dimensionMultipliers[i - 1] = currentMultiplier;
		currentMultiplier *= dimensionSizes[i - 1];
	}

	//Initialize all cells to default.
	cells = (Cell *) malloc(sizeof(Cell) * numCells);
	for(int i = 0; i < numCells; ++i) {
		int currCount = i;
		int* cellCoordinates = (int *) malloc(sizeof(int) * numDimensions);

		for (int j = 0; j < numDimensions; ++j) {
			cellCoordinates[j] = currCount / dimensionMultipliers[j];
			currCount = currCount % dimensionMultipliers[j];
		}

		cells[i] = *(new Cell(numDimensions, cellCoordinates));
		cells[i].setEllerSet(i);
	}*/
}

Maze::~Maze() {
	free(cells);
	free(dimensionSize);
}

void Maze::hackInit() {
	
	numDimensions = 4;
	dimensionSize = (int *) malloc(sizeof(int) * numDimensions);
	numCells = 256;
	
	for(int i = 0; i < numDimensions; i++) {
		dimensionSize[i] = 4;
	}
	
	cells = (Cell *) malloc(sizeof(Cell) * numCells);
	
	cellList *list;
	
	//Get first line of cells.
	for (int i = 0; i < 64; ++i) {
		list = getCells(cells, i * dimensionSize[0], dimensionSize[0]);
		//Randomly connect cells.
		randomlyConnect(list, 1, dimensionSize);
	}
	
	for (int i = 0; i < 16; ++i) {
		list = getCells(cells, i * dimensionSize[0] * dimensionSize[1], dimensionSize[0] * dimensionSize[1] * 2);
		randomlyConnect(list, 2, dimensionSize);
	}
	
	for (int i = 0; i < 4; ++i) {
		list = getCells(cells, i * dimensionSize[0] * dimensionSize[1] * dimensionSize[2], dimensionSize[0] * dimensionSize[1] * dimensionSize[2] * 2);
		randomlyConnect(list, 3, dimensionSize);
	}
	
	//list = getCells(cells, i * dimensionSize[0] * dimensionSize[1] * dimensionSize[2], dimensionSize[0] * dimensionSize[1] * dimensionSize[2] * 2);
}

int Maze::getNumDimensions() {
	return numDimensions;
}

int *Maze::getDimensionSizes() {
	return dimensionSize;
}

Cell *Maze::getCell(int *coordinates) {

	int index = 0;
	int index_multiplier = 1;
	for (int i = (getNumDimensions() - 1); i >= 0; --i) {
		index += coordinates[i] * index_multiplier;
		index_multiplier *= dimensionSize[i];
	}

	check(index < numCells, "Index %d larger than the number of cells %d.", index, numCells);
	check(index_multiplier != 0, "Index multiplier was zero.");

	//cells[index] dereferences cell pointer, must add & to return pointer.
	return &(cells[index]);

error:
	return NULL;
}

Neighbors* Maze::getNeighbors(int *coordinates) {
	Cell *c = getCell(coordinates);
	int numWalls = 0;
	for(int i = 0; i < getNumDimensions(); ++i) {
		if(c->isWall(i, 0)) {
			++numWalls;
		}
		if(c->isWall(i, 1)) {
			++numWalls;
		}
	}

	Neighbors *out = (Neighbors *) malloc(sizeof(Neighbors));
	out->numDimensions = getNumDimensions();
	out->numNeighbors = numDimensions * 2 - numWalls;
	out->coordinates = (int *) malloc(sizeof(int) * out->numDimensions * out->numNeighbors);

	int neighborsCount = 0;

	for (int i = 0; i < out->numDimensions; ++i) {
		int currentZIndex = neighborsCount * getNumDimensions();

		if (!c->isWall(i,0)) {
			for (int j = 0; j < getNumDimensions(); ++j) {
				out->coordinates[currentZIndex + j] = coordinates[j];
				out->coordinates[currentZIndex + i]--;
			}
			++neighborsCount;
		}

		if (!c->isWall(i,1)) {
			for (int j = 0; j < getNumDimensions(); ++j) {
				out->coordinates[currentZIndex + j] = coordinates[j];
				out->coordinates[currentZIndex + i]++;
			}
			++neighborsCount;
		}
	}

	check(out->numNeighbors == neighborsCount, "Expected nbrCount != actualNbrCount");

	return out;
error:
	return NULL;
}
