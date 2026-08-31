#pragma once
#include<iostream>
#include<string>
#include"Validation.h"
#include"Person.h"
using namespace std;

class Client : public Person{
private:
	double balance = 0.0;
	double enterBal(double balance) {
		bool isValid = false;
		while (!isValid) {
		
			if (!Validation::validBal(balance)) {
				cout << "Please try again \n";
				cout << "Enter your Balance : ";
				cin >> balance;
			}
			else isValid = true;
			
		}
		return balance;
	}
public:

	//Setter
	void setBalance(double balance) {
		double bal = enterBal(balance);
		this->balance = bal;
	}
	//Getter
	double getBalance() {
		return balance;
	}

	//Methods
	void deposit(double amount) {
		balance += amount;
		cout << "Deposit completed successfully.\n";
	}
	void withdraw(double amount) {
		if (!Validation::validAmount(amount, balance)) {
			cout << "Withdraw completed unsuccessfully.\n";
			return;
		}
		balance -= amount;
		cout << "Withdraw completed successfully.\n";
	}
	void transferTo(double amount, Client& recipient) {
		if (!Validation::validAmount(amount, balance)) {
			cout << "Transfer completed Unsuccessfully.\n";
			return;
		}
		recipient.balance += amount;
		balance -= amount;
		cout << "Transfer completed successfully.\n";
	}
	void checkBalance() {
		cout << "\n\n";

		cout << "BALANCE : " << balance << "\n\n";
	}
	void DisplayInfo() override {
		cout << "==============INFO=============\n";
		Person::DisplayInfo();
		cout << "Balance   : " << balance << "\n";
		cout << "==============================\n";

	}
	
};

