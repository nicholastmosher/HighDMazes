#include "Generation.h"
#include <time.h>
#include <math.h>

int getSharedSetNumber(cellList *cells) {

	debug("Executing getSharedSetNumber()");

	//Iterate over all cells and determine if there's a common set number.
	int setNum = -1;
	int i = 0, s = -1;
	for(i = 0; i < cells->size(); i++) {

		s = (*cells)[i]->getEllerSet();
		debug("Cell %d in ellerSet %d.", i, s);

		//If the set number is -1, set it to s (first cell).
		if(setNum == -1) {
			setNum = s;
			continue;
		}

		//If s does not match setNum, then cell i is an outlier.
		if(s != setNum) {
			debug("Cell %d in set %d is an outlier; not in set %d.", i, s, setNum);
			return -1;
		}
	}

	//If we successfully exited the loop, all sets must match.
	check(setNum != -1, "Set number was never assigned.");
	debug("Found common set number: %d.", setNum);
	return setNum;
error:
	return -1;
}

cellList *getCellsWithSet(cellList *cells, int setNumber) {

	cellList *setCells = new cellList();

	//Iterate over all cells and find the cells in the given set.
	int i = 0, s = -1;
	for(i = 0; i < cells->size(); i++) {

		s = (*cells)[i]->getEllerSet();
		debug("Cell %d in ellerSet %d.", i, s);

		if(s == setNumber) {

			//Add the matching cell to the new set.
			setCells->push_back((*cells)[i]);
			debug("Found cell %d in set %d.", i, s);
		}
	}

	return setCells;
}

void joinSets(cellList *persistentSet, cellList *oldSet) {

	int i = 0;

	int persistNum = getSharedSetNumber(persistentSet);
	int oldNum;
	int setNum;
	check(persistNum != -1, "Cells in persistent set don't share a set number.");
	oldNum = getSharedSetNumber(oldSet);
	check(oldNum != -1, "Cells in old set don't share a set number.");
	setNum = (persistNum < oldNum ? persistNum : oldNum);

	//For each element in the oldSet, change ellerSet and move to persistentSet.
	for(i = 0; i < oldSet->size(); i++) {
		(*oldSet)[i]->setEllerSet(setNum);
		persistentSet->push_back((*oldSet)[i]);
	}

	//Free the old set.
	delete(oldSet);
error:
	return;
}

cellList* getCells(cellList* in, int offset, int size) {
	cellList *out = new cellList(size);

	for (int i = 0; i < size; ++i) {
		out->push_back((*in)[offset + i]);
	}

	return out;
}

void generatePath(Maze *maze) {

	int dimensions = maze->getNumDimensions();
	int *dimensionSizes = maze->getDimensionSizes();
}

//isAdjacent(Cell *cell);
void knockWalls(std::vector<cellList> superset) {
	int numSets = superset.size();
	int i = 0;
	int j = 0;
	while (i < numSets) {
		while (j < numSets) {
			if (superset[i][superset[i].size() - 1]->isAdjacent(superset[j][0])) {
				srand(time(NULL));
				double threshold = (sqrt(superset.size()) / superset.size());
				double rn = (rand() % 10 + 1) / 10; // generate between 0.1 to 1.0
				if (rn > threshold) {
					joinSets(&superset[i], &superset[j]);
					superset.erase(superset.begin() + j);
				}
				else {
					++j;
				}
			}
		}
		++i;
		j = 0;
	}
}
