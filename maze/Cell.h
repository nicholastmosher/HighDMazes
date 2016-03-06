#ifndef __cell_h__
#define __cell_h__

#include <stdlib.h>

/**
 * Represents a single room in a maze.
 */
class Cell {

private:

	/**
	 * Indicates how many dimensions this cell has.
	 */
	int numDimensions;

	/**
	 * The coordinates of this cell in the maze.
	 */
	int *coordinates;

	/**
	 * Determines whether there are walls on each end of each dimension.
	 * Since in each dimension there are two directions to travel (+/-),
	 * the number of possible walls in each cell is (numDimensions * 2).
	 *
	 * Wall values for an N-dimensional maze are stored as follows:
	 * {0+, 0-, 1+, 1-, ..., N+, N-}
	 */
	bool *walls;

	/**
	 * Represents the set that this cell belongs to in the context of Eller's
	 * algorithm.
	 */
	int ellerSet;

public:

	/**
	 * Constructs a cell with the given number of dimensions at the given
	 * coordinates.
	 */
	Cell (int numDims, int *coords);
	~Cell();

	/**
	 * Identifies up to two neighbors of this cell along the given dimension.
	 */
	void identifyNeighbors(int dimension);

	/**
	 * Puts a wall at the given location. The locations are incremental over
	 * the number of dimensions and the two possible directions for that
	 * dimension.
	 *
	 * For a cell with N dimensions, the wall indexes are:
	 *
	 *	{0+, 0-, 1+, 1-, ..., N+, N-}
	 *	 0	 1	 2	 3		  2N  2N+1
	 */
	void createWall (int wallIndex);

	/**
	 * Removes a wall from the given location. The locations are incremental over
	 * the number of dimensions and the two possible directions for that
	 * dimension.
	 *
	 * For a cell with N dimensions, the wall indexes are:
	 *
	 *	{0+, 0-, 1+, 1-, ..., N+, N-}
	 *	 0	 1	 2	 3		  2N  2N+1
	 */
	void deleteWall (int wallIndex);

	/**
	 * Determines whether this cell has a wall (true) or opening (false) in the
	 * given dimension on the given side.
	 *
	 * @param dimension The dimension number to check walls for.
	 * @param side The side (true/false corresponds to front/back) to check.
	 */
	bool isWall (int dimension, bool side);

	/**
	 * Determines whether the cell at the given pointer is adjacent to this one.
	 */
	bool isAdjacent(Cell *cell);

	void setEllerSet(int set);
	int getEllerSet();

	/**
	 * Gets the cell's coordinates in array form
	 */
	int* getCoordinates();

	/**
	 * Gets the cell's walls in boolean array form, in the format stated in
	 * data member declaration
	 */
	bool* getWalls();
};

#endif //__cell_h__
