#include "Maze.h"

/**
 * Constructs a new maze with the given number of dimensions, with
 * the specified size for each dimension.
 */
Maze::Maze (int numDimensions, int* dimensionSizes) {
    
    //Initialize the number of dimensions and the size of each dimension.
    numDimensions = numDimensions;
    dimensionSize = (int *) malloc(sizeof(int) * numDimensions);
    int numCells = 1;
    
    //Copy each dimension size into the local array.
    for(int i = 0; i < numDimensions; ++i) {
        dimensionSize[i] = dimensionSizes[i];
        numCells *= dimensionSize[i];
    }
    
    //Initialize all cells to default.
    cells = (Cell *) malloc(sizeof(Cell) * numCells);
    for(int i = 0; i < numCells; ++i) {
        cells[i] = *(new Cell(numDimensions));
    }
}

int Maze::getNumDimensions() {
    return numDimensions;
}

Cell* Maze::getCell(int *coordinates) {
    
    int index = 0;
    int index_multiplier = 1;
    for (int i = (getNumDimensions() - 1); i >= 0; --i) {
        index += coordinates[i] * index_multiplier;
        index_multiplier *= dimensionSizes[i];
    }
    
    check(index_multiplier != 0, "Index multiplier was zero.");
    
    //cells[index] dereferences cell pointer, must add & to return pointer.
    return &(cells[index]);
error:
    return NULL;
}

Neighbors* Maze::getNeighbors(int *coordinates) {
    Cell* c = getCell(coordinates);
    int numWalls = 0;
    for (int i = 0; i < getNumDimensions(); ++i) {
        if (c.isWall(i, 0)) {
            ++numWalls;
        }
        if (c.isWall(i, 1)) {
            ++numWalls;
        }
    }
    
    Neighbors* out = (Neighbors *) malloc(sizeof(Neighbors));
    out->numDimensions = getNumDimensions();
    out->numNeighbors = numWalls;
    out->coordinates = (int *) malloc(sizeof(int) * out->numDimensions * out->numNeighbors)
    
}

void Maze::generatePath() {
    
    
}