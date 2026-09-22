#pragma once
#include "Admin.h"
#include <vector>
using namespace std;

class Parser {
public:

	// id-name-bal-pass
	static vector<string> split(string line);

	static Client parseToClient(string line);

	static Employee parseToEmployee(string line);

	static Admin parseToAdmin(string line);


};

