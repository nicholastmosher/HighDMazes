#include "Cell.h"

Cell::Cell (int numDimensions) {
    const int maxWalls = 2 * numDimensions;
    Cell::walls = (bool *) malloc(sizeof(bool) * maxWalls);
    
    for(int i = 0; i < maxWalls; ++i) {
        Cell::walls[i] = 1;
    }
}

// 0+, 0-, 1+, 1-, 2+, 2-...
void Cell::createWall (int wallIndex) {
    Cell::walls[wallIndex] = 1;
}

void Cell::deleteWall (int wallIndex) {
    Cell::walls[wallIndex] = 0;
}

bool Cell::isWall (int dimension, bool side) {
    int index = 2 * dimension + side;
    return Cell::walls[index];
}