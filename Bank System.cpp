#include <iostream>
#include <string>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Validation.h"
using namespace std;

int main(){
	int id; string name, pass; double bal;
	cout << " Enter id : ";cin >> id;
	Client c;
	c.setId(id);
	cin.ignore();// clear buffer
	cout << " Enter name : ";getline(cin, name);
	c.setName(name);
	cout << " Enter pass : ";getline(cin,pass);
	c.setPassword(pass);
	cout << "Enter bal :";cin >> bal;
	c.setBalance(bal);

	c.DisplayInfo();

	
}