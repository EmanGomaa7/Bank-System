#pragma once
#include<iostream>
#include"Validation.h"
using namespace std;
class Person
{
private :
	int id;
	string name, password;
	string enterName(string& name) {
		bool isValid = false;
		while (!isValid) {
			
			if (!(Validation::validName(name))){
				cout << "Please try again . \n";
				cout << "Enter your name : ";
				getline(cin, name);
			}
			else isValid = true;
		}
		return name;
	}
	string enterPass(string& password) {
		bool isValid = false;
		while (!isValid) {
			if (!(Validation::validPass(password))) {
				cout << "Please try again \n";
				cout << "Enter your password : ";
				getline(cin, password);
			}
			else isValid = true;

		}
		return password;
	}
public:
	
	//Setters:
	void setId(int id) {
		this->id = id;
	}
	void setName(string name) {
		string Name = enterName(name);
		this->name = Name;
	}
	void setPassword(string password) {
		string pass = enterPass(password);
		this->password = pass;
	}

	//Getters:
	int getId() {
		return id;
	}
	string getName() {
		return name;
	} 
	string getPassword() {
		return password;
	}
	
	//Method:
	virtual void DisplayInfo() {
		cout << "==============INFO=============\n";
		cout << "Id        : " << id << "\n";
		cout << "Name      : " << name << "\n";
		cout << "password  : " << password << "\n";
	}
	
	
};

