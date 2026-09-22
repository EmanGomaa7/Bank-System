#include"Person.h"
#include"Validation.h"
using namespace std;

	
	string Person::enterName(string& name) {
		bool isValid = false;
		while (!isValid) {

			if (!(Validation::validName(name))) {
				cout << "Please try again . \n";
				cout << "Enter your name : ";
				getline(cin, name);
			}
			else isValid = true;
		}
		return name;
	}
	string Person::enterPass(string& password) {
		bool isValid = false;
		while (!isValid) {

			if (!(Validation::validPass(password))) {

				cout << "Please try again \n";
				cout << "Enter your password :\n ";
				getline(cin, password);
			}
			else isValid = true;

		}
		return password;
	}

	//Setters:
	void Person::setId(int id) {
		this->id = id;
	}
	void Person::setName(string name) {
		string Name = enterName(name);
		this->name = Name;
	}
	void Person::setPassword(string password) {
		string pass = enterPass(password);
		this->password = pass;
	}

	//Getters:
	int Person::getId() {
		return id;
	}
	string Person::getName() {
		return name;
	}
	string Person::getPassword() {
		return password;
	}

	//Method:
	void Person::DisplayInfo() {
		cout << "Id        : " << id << "\n";
		cout << "Name      : " << name << "\n";
		cout << "password  : " << password << "\n";
	}



