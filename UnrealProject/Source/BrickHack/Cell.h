#include <stdint.h>
#include <vector>
#include <stdbool.h>

/**
 * Represents a single room in a maze.
 */
class Cell {

private:

    /**
     * Determines whether there are walls on each end of each dimension.
     * Since in each dimension there are two directions to travel (+/-),
     * the number of possible walls in each cell is (numDimensions * 2).
     * 
     * Wall values for an N-dimensional maze are stored as follows:
     * {0+, 0-, 1+, 1-, ..., N+, N-}
     */
    bool *walls;

public:

    /**
     * Constructs a cell with the given number of dimensions.
     */
    Cell (int numDimensions);
    void createWall (int wallIndex); // 0+, 0-, 1+, 1-, 2+, 2-...
    void deleteWall (int wallIndex);
    bool isWall (int dimension, bool side);
}