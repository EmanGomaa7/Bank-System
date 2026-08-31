#pragma once
#include<iostream>
#include<string>
using namespace std;
class Validation {
public:

	static bool validName(string name) {
		if (name.size() < 5 || name.size() > 20) {
			cout << "This Name is invalid ,It should have between 5 and 20 characters.\n";
		
			return false;
		}
		for (int i = 0; i < name.size();i++) {
			if (!(isalpha(name[i]) || name[i] == ' ')) {
				cout << "This Name is invalid ,It should contain only letters.\n";
				return false;
			}
		}
		return true;
	}
	static bool validPass(string password) {
		bool Size = true;			cout << password.size() << endl;
		if (password.size() < 8 || password.size() > 20) {
			Size = false;
		}
		bool specialChar = false , space = false;

		for (int i = 0; i < password.size(); i++) {
			if (password[i] == ' ') {
				space = true;
			}
			if (ispunct(password[i]))specialChar = true;
		}
		
		if (!specialChar || !Size || space) {
			cout << specialChar << " " << Size << " " << space << endl;
			cout << "Password must be between 8 and 20 characters, contain at least one special character,\n and must not contain spaces.\n";
			return false;
		}
		return true;
	}
	static bool validBal(double balance) {
		if (balance < 1500) {
			cout << "This balance is below the minimum limit.\n";
			return false;
		}
		return true;
	}
	static bool validAmount(double amount, double balance) {
		if (amount > balance) {
			cout << "The amount exceeds the available balance.\n";
			return false;
		}
		return true;
	}

};
