#include "Test.h"

int test() {

	check(test_generation() == 0, "Failed test_generation()");

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
