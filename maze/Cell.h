#include <stdint.h>
#include <vector>
#include <stdbool.h>

/**
 * Represents a single room in a maze.
 */
class Cell {

private:
    // 0+, 0-, 1+, 1-, 2+, 2-...
    bool *walls;

public:
    Cell (int numDimensions);
    void createWall (int wallIndex); // 0+, 0-, 1+, 1-, 2+, 2-...
    void deleteWall (int wallIndex);
    bool isWall (int dimension, bool side);
}