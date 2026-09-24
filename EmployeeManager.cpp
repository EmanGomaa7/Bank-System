#include "EmployeeManager.h"
#include "FilesHelper.h"
#include "FileManager.h"

void EmployeeManager::printEmployeeMenu() {
	cout << "===============EMPLOYEE MENU=================\n\n";
	cout << "1.Display my info.\n";
	cout << "2.Add new client.\n";
	cout << "3.Search for client.\n";
	cout << "4.List all clients.\n";
	cout << "5.Edit client info.\n";
	cout << "6.Update password.\n";
	cout << "7.Logout.\n\n";
}

void EmployeeManager::updatePassword(Employee* employee) {
	cout << "==============Update Password===============\n";
	string password;
	cout << "Enter your password :";
	cin >> ws;
	getline(cin, password);
	while (password != employee->getPassword()) {
		cout << "Incorrect password ,Please try again .\n";
		cout << "Enter your password :";
		getline(cin, password);
	}
	cout << "Enter the new password :";
	getline(cin, password);
	employee->setPassword(password);
	FileManager fm;
	fm.updateEmployee();
	cout << "Password updated successfully.\n";
}

void EmployeeManager::newClient(Employee* employee) {
	Client c;
	string name, password;
	double balance;

	cout << "Enter client name :";
	cin >> ws;
	getline(cin, name);
	c.setName(name);

	cout << "Enter client password :";
	getline(cin, password);
	c.setPassword(password);

	cout << "Enter client balance :";
	cin >> balance;
	c.setBalance(balance);

	c.setId(FilesHelper::getLast("lastIdClient.txt") + 1);
	employee->addClient(c);
}

void EmployeeManager::listAllClients(Employee* employee) {
	employee->listClient();
}

void EmployeeManager::searchForClient(Employee* employee) {
	int id;
	cout << "Enter client id :";
	cin >> id;
	Client* c = employee->searchClient(id);
	if (c == nullptr) {
		cout << "No client found with this ID.\n";
		return;
	}
	c->DisplayInfo();
	delete c;
}

void EmployeeManager::editClientInfo(Employee* employee) {
	int id;
	string name, password;
	double balance;

	cout << "Enter client id :";
	cin >> id;
	Client* c = employee->searchClient(id);
	if (c == nullptr) {
		cout << "No client found with this ID.\n";
		return;
	}
	delete c;

	cout << "Enter new name :";
	cin >> ws;
	getline(cin, name);
	cout << "Enter new password :";
	getline(cin, password);
	cout << "Enter new balance :";
	cin >> balance;

	employee->editClient(id, name, password, balance);
}

Employee* EmployeeManager::login(int id, string password) {
	for (int i = 0; i < FilesHelper::Employees.size(); i++) {
		if (FilesHelper::Employees[i].getId() == id &&
			FilesHelper::Employees[i].getPassword() == password) {
			cout << "Login Successfully.\n";
			cout << "Welcome ," << FilesHelper::Employees[i].getName() << "\n";
			return &FilesHelper::Employees[i];
		}
	}
	return nullptr;
}

bool EmployeeManager::employeeOptions(Employee* employee) {
	printEmployeeMenu();
	cout << "Enter your choice:";
	int choice; cin >> choice;
	switch (choice) {
	case 1: employee->DisplayInfo(); break;
	case 2: newClient(employee); break;
	case 3: searchForClient(employee); break;
	case 4: listAllClients(employee); break;
	case 5: editClientInfo(employee); break;
	case 6: updatePassword(employee); break;
	case 7: return false;
	default:
		cout << "Invalid choice.\n";
	}
	return true;
}
