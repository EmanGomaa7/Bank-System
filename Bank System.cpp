#include <iostream>
#include <string>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Validation.h"
using namespace std;

int main(){
	//testing
	int id; string name, pass; double bal;
	cout << " Enter id : ";cin >> id;
	Client c , b;
	c.setId(id);
	cin.ignore();// clear buffer
	cout << " Enter name : ";getline(cin, name);
	c.setName(name);
	cout << " Enter pass : ";getline(cin,pass);
	c.setPassword(pass);
	cout << "Enter bal :";cin >> bal;
	c.setBalance(bal);
	c.DisplayInfo();
	c.deposit(300);
	c.checkBalance();
	c.withdraw(2200);
	c.checkBalance();
	c.transferTo(800, b);
	c.checkBalance();
	//=====================================================
	Employee e;
	int Id; string Name, Pass; double sal;
	cout << " Enter id : "; cin >> Id;
	e.setId(Id);
	cin.ignore();
	cout << " Enter name : ";getline(cin, Name);
	e.setName(Name);
	cout << " Enter pass : ";getline(cin, Pass);
	e.setPassword(Pass);
	cout << "Enter sal :";cin >> sal;
	e.setSalary(sal);
	e.DisplayInfo();
	//====================================================
	


	
}