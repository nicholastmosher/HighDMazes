typedef struct _neighbors {
    
    int numNeighbors;
    int numDimensions;
    int coordinates[numNeighbors][numDimensions];
} Neighbors;

/**
 * The master data record for a single maze.
 */
class Maze {

private:

    /**
     * The number of dimensions in this maze.
     */
    int numDimensions;
    
    /**
     * A pointer to an array of sizes for each dimension of the maze. The size
     * of the array is equal to "numDimensions".
     */
    int *dimensionSize;
    
    /**
     * A pointer to an array of cells. The number of cells in an N-dimensional
     * maze is equal to:
     * 
     *  dimensionSize[0]   *
     *  dimensionSize[1]   *
     *  ...
     *  dimensionSize[N];
     */
    Cell *cells;

public:

    /**
     * Constructs a maze of the given number of dimensions, where each
     * dimension has a specified size determined by *dimensionSizes.
     * 
     * For a maze with N dimensions, the size of each dimension is:
     * 
     *  Dimension 0:    dimensionSizes[0];
     *  Dimension 1:    dimensionSizes[1];
     *  ...             ...
     *  Dimension N:    dimensionSizes[N];
     */
    Maze(int numDimensions, int *dimensionSizes);
    
    /**
     * Returns the number of dimensions in this maze.
     */
    int getNumDimensions();
    
    /**
     * Returns the cell located at the given coordinates. The format of the
     * coordinates for an N-dimensional maze is:
     * 
     *  D0 D1 D2 D3 ...DN
     *  [0][0][0][0]...[0]
     */
    Cell getCell(int *coordinates);
    
    /**
     * Returns a struct of neighbors for the cell located at the given
     * coordinates.The format of the coordinates for an N-dimensional maze is:
     * 
     *  D0 D1 D2 D3 ...DN
     *  [0][0][0][0]...[0]
     * 
     * The returned struct contains the number of neighbors to that cell,
     * the number of dimensions in which it has neighbors, and an array
     * of coordinates of those neighbors.
     */
    Neighbors *getNeighbors(int *coordinates);
}