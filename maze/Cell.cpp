#include "Cell.h"

Cell::Cell (int numDimensions) {
    const int maxWalls = 2 * numDimensions;
    walls = malloc(sizeof(bool) * maxWalls);
    for (int i = 0; i < maxWalls; ++i)
        walls[i] = 1; //TODO hey guys pls check if you want walls up or walls down when creating a wall
}


// 0+, 0-, 1+, 1-, 2+, 2-...
void Cell::createWall (int wallIndex) {
    Cell.walls[wallIndex] = 1;
}

void Cell::deleteWall (int wallIndex) {
    Cell.walls[wallIndex] = 0;
}

bool* Cell::getWalls() {
    return Cell.walls;
}

