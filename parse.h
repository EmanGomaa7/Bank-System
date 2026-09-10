#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

class Parse {
public:

	// id#name#bal#pass
	static vector<string> split(string line) {
		vector<string>sp(4);
		int idx = 0;
		string temp;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '#' && idx != 3) {
				sp[idx] = temp;
				temp = "";
				idx++;
				continue;
			}
			temp += line[i];
		}
	}

	static Client parseToClient(string line) {
		Client client;
		vector<string>spLine(4);
		spLine = split(line);
		client.setId(stoi(spLine[0]));
		client.setName(spLine[1]);
		client.setBalance(stod(spLine[2]));
		client.setPassword(spLine[3]);
		return client;
	}

	static Employee parseToEmployee(string line) {
		Employee employee;
		vector<string>spLine(4);
		spLine = split(line);
		employee.setId(stoi(spLine[0]));
		employee.setName(spLine[1]);
		employee.setSalary(stod(spLine[2]));
		employee.setPassword(spLine[3]);
		return employee;
	}

	static Admin parseToAdmin(string line) {
		Admin admin;
		vector<string>spLine(4);
		spLine = split(line);
		admin.setId(stoi(spLine[0]));
		admin.setName(spLine[1]);
		admin.setSalary(stod(spLine[2]));
		admin.setPassword(spLine[3]);
		return admin;
	}


};

