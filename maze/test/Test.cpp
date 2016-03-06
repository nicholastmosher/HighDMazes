#include "Test.h"

int test() {

	debug("Starting tests.");
	check(test_generation() == 0, "Failed test_generation()");
	check(test_cellConstruction() == 0, "Failed test_cellConstruction");

	return 0;
error:
	return 1;
}

int test_getSharedSetNumber() {

	log_info("Testing getSharedSetNumber().");

	int dimensions = 3;
	int coordinates[3] = {0,0,0};
	cellList *cells = new cellList();
	int i = 0;

	Cell *c = new Cell(dimensions, coordinates);
	c->setEllerSet(2);
	cells->push_back(c);
	int gotSetNumber;
	check((gotSetNumber = getSharedSetNumber(cells)) == 2,
			"Expected SharedSetNumber to be %d, got %d.", 2, gotSetNumber);

	coordinates[2] = 1;
	c = new Cell(dimensions, coordinates);
	c->setEllerSet(2);
	cells->push_back(c);
	check((gotSetNumber = getSharedSetNumber(cells)) == 2,
			"Expected SharedSetNumber to be %d, got %d.", 2, gotSetNumber);

	coordinates[2] = 2;
	c = new Cell(dimensions, coordinates);
	c->setEllerSet(2);
	cells->push_back(c);
	check((gotSetNumber = getSharedSetNumber(cells)) == 2,
			"Expected SharedSetNumber to be %d, got %d.", 2, gotSetNumber);

	coordinates[2] = 3;
	c = new Cell(dimensions, coordinates);
	c->setEllerSet(2);
	cells->push_back(c);
	check((gotSetNumber = getSharedSetNumber(cells)) == 2,
			"Expected SharedSetNumber to be %d, got %d.", 2, gotSetNumber);

	coordinates[2] = 4;
	c = new Cell(dimensions, coordinates);
	c->setEllerSet(3);
	cells->push_back(c);
	check((gotSetNumber = getSharedSetNumber(cells)) == -1,
			"Expected SharedSetNumber to be %d, got %d.", -1, gotSetNumber);

	//Free all of those cells.
	for(i = 0; i < cells->size(); i++) {
		delete((*cells)[i]);
	}
	delete(cells);

	log_info("Passed getSharedSetNumber.");

	return 0;
error:
	return 1;
}

int test_getCellsWithSet() {

	log_info("Testing getCellsWithSet().");

	return 0;
error:
	return 1;
}

int test_joinSets() {

	log_info("Testing joinSets().");

	return 0;
error:
	return 1;
}

int test_generation() {

	check(test_getSharedSetNumber() == 0, "Failed test_getSharedSetNumber()");
	check(test_getCellsWithSet() == 0, "Failed test_getCellsWithSet()");
	check(test_joinSets() == 0, "Failed test_joinSets()");

	return 0;
error:
	return 1;
}

int test_cellConstruction() {
	int coordinates[3] = {3,4,5};
	Cell* c = new Cell(3, coordinates);
	int* cell_coordinates = c->getCoordinates();
	check(cell_coordinates[0] == 3, "Failed test_cellConstruction()");
	check(cell_coordinates[1] == 4, "Failed test_cellConstruction()");
	check(cell_coordinates[2] == 5, "Failed test_cellConstruction()");

	// debug("Running delete c");

	delete(c);

	return 0;
error:
	return 1;
}
