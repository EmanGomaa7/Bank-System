#include "Validation.h"
#include<cctype>

	bool Validation::validName(string name) {
		if (name.size() < 3 || name.size() > 20) {
			cout << "This Name is invalid ,It should have between 3 and 20 characters.\n";
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

	bool Validation::validPass(string password) {

		bool Size = true, specialChar = false, space = false;
		if (password.size() < 8 || password.size() > 20) {
			Size = false;
		}

		for (int i = 0; i < password.size(); i++) {
			if (password[i] == ' ') {
				space = true;
				break;
			}
			if (ispunct(password[i]) != 0)specialChar = true;
		}

		if (!specialChar || !Size || space) {
			cout << "Password must be between 8 and 20 characters, contain at least one special character,\n and must not contain spaces.\n";
			return false;
		}
		return true;
	}

	bool Validation::validBal(double balance) {
		if (balance < 1500) {
			cout << "This balance is below the minimum limit(1500).\n";
			return false;
		}
		return true;
	}

	bool Validation::validAmount(double amount, double balance) {
		if (amount > balance) {
			cout << "The amount exceeds the available balance.\n";
			return false;
		}
		return true;
	}

	bool Validation::validSalary(double salary) {
		if (salary < 5000) {
			cout << "Salary must be at least 5000.\n";
			return false;
		}
		return true;
	}

