#include "Maze.h"

Maze::Maze (int numDimensions, int* dimensionSizes) {
    Maze::numDimensions = numDimensions;
    Maze::dimensionSizes = malloc(sizeof(int) * this.numDimensions);
    int numCells = 1;
    
    for (int i = 0; i < this.numDimensions; ++i) {
        Maze::dimensionSizes[i] = dimensionSize[i];
        numCells *= dimensionSize[i];
    }
    
    Maze::cells = malloc(sizeof(Cell) * numCells);
    for (int i = 0; i < numCells; ++i) {
        cells[i] = new Cell(Maze::numDimensions);
    }
}

int getNumDimensions() {
    return Maze::numDimensions;
}

Cell *getCell(int *coordinates) {
    Cell *out;
    return out;
}

Neighbors *getNeighbors(int *coordinates) {
    Neighbors *out;
    return out;
}