#ifndef __generation_h__
#define __generation_h__

#include "Maze.h"
#include <vector>

typedef std::vector<Cell*> cellList;

/**
 * Returns the number of the set shared by all cells in the given cellList, or
 * -1 if they do not all share the same set number.
 */
int getSharedSetNumber(cellList *cells);

/**
 * Returns all cells from the given cellList that share the given set number.
 */
cellList *getCellsWithSet(cellList *cells, int setNumber);

/**
 * Adds all elements of the oldSet to the persistetSet, while also reassigning
 * the internal set number of each cell in that set.
 */
void joinSets(cellList *persistentSet, cellList *oldSet);

/**
 * Returns a pointer to a vector containing all cells in the given row of
 * the given dimension.
 */
cellList *getCellsInDimensionByRow(Maze *maze, int dimension, int row);

void generatePath(Maze *maze);

#endif //__generation_h__
