#include "Generation.h"

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

	int setNum = getSharedSetNumber(persistentSet);
	check(setNum != -1, "Cells in persistent set don't share a set number.");

	//For each element in the oldSet, change ellerSet and move to persistentSet.
	for(i = 0; i < oldSet->size(); i++) {
		(*oldSet)[i]->setEllerSet(setNum);
		persistentSet->push_back((*oldSet)[i]);
	}

	//Free the old set.
	free(oldSet);
error:
	return;
}

cellList *getCellsInDimensionByRow(Maze *maze, int dimension, int row) {

}

void generatePath(Maze *maze) {

}
