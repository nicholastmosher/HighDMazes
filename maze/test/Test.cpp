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

	return 0;
error:
	return 1;
}

int test_generation() {

	check(test_getSharedSetNumber() == 0, "Failed test_getSharedSetNumber()");

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