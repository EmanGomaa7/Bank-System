#pragma once
#include<iostream>
#include<string>
using namespace std;
class Validation {
public:

	static bool validName(string name);

	static bool validPass(string password);

	static bool validBal(double balance);

	static bool validAmount(double amount, double balance);

	static bool validSalary(double salary);

};