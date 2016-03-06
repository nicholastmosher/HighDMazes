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
 * the internal set number of each cell in that set. This deletes oldSet.
 */
void joinSets(cellList *persistentSet, cellList *oldSet);

/**
 * Returns a set of cells starting from an offset away from the base pointer,
 * stretching across 'size' number of cells.
 */
cellList *getCells(Cell *in, int offset, int size);

/**
 * Iterates over two cells at a time from the cellList, and for every pair
 * of cells adjacent in the given dimension, they are randomly connected if
 * they don't share a set.
 */
void randomlyConnect(cellList *cells, int dimension);

void newRow(

#endif //__generation_h__
