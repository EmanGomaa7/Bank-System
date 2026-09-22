#pragma once
#include"Person.h"
using namespace std;

class Client : public Person{
private:
	double balance = 0.0 ;
	double enterBal(double& balance);
public:

	//Setter
	void setBalance(double balance);
	//Getter
	double getBalance();

	//Methods
	void deposit(double amount);
	void withdraw(double amount);
	void transferTo(double amount, Client& recipient);
	void checkBalance();
	void DisplayInfo() override;
	
};

