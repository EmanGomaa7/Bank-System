#pragma once
#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
	int id;
	string name, password;
	string enterName(string& name);
	string enterPass(string& password);
public:

	//Setters:
	void setId(int id);
	void setName(string name);
	void setPassword(string password);

	//Getters:
	int getId();
	string getName();
	string getPassword();

	//Method:
	virtual void DisplayInfo();

};

