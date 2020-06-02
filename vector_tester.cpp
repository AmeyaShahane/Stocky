#include "vector_tester.h"
#include <iostream>
#include <vector>
#include <string>

/*
Testing vector based on net increases and decreases across open and closed vector values
*/

std::string vector_tester::stock_changes(std::vector<double> x) {
	int i = 1;

	if (x.size() == 0) {
		return "empty";
	}

	else if (i != 0 && x.at(i - 1) > x.at(i)) {
		return "decrease";
	}

	else if (i != 0 && x.at(i - 1) < x.at(i)) {
		return "increase";
	}

	else if (i != 0 && x.at(i - 1) == x.at(i)) {
		return "green";
	}

	else {
		return "InvalidInput";
	}
}
