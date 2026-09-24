#include "AdminManager.h"
#include "EmployeeManager.h"
#include "FilesHelper.h"
#include "FileManager.h"

void AdminManager::printAdminMenu() {
	cout << "================ADMIN MENU===================\n\n";
	cout << "1.Display my info.\n";
	cout << "2.Add new client.\n";
	cout << "3.Search for client.\n";
	cout << "4.List all clients.\n";
	cout << "5.Edit client info.\n";
	cout << "6.Add new employee.\n";
	cout << "7.Search for employee.\n";
	cout << "8.List all employees.\n";
	cout << "9.Edit employee info.\n";
	cout << "10.Update password.\n";
	cout << "11.Logout.\n\n";
}

void AdminManager::updatePassword(Admin* admin) {
	cout << "==============Update Password===============\n";
	string password;
	cout << "Enter your password :";
	cin >> ws;
	getline(cin, password);
	while (password != admin->getPassword()) {
		cout << "Incorrect password ,Please try again .\n";
		cout << "Enter your password :";
		getline(cin, password);
	}
	cout << "Enter the new password :";
	getline(cin, password);
	admin->setPassword(password);
	FileManager fm;
	fm.updateAdmin();
	cout << "Password updated successfully.\n";
}

void AdminManager::newEmployee(Admin* admin) {
	Employee e;
	string name, password;
	double salary;

	cout << "Enter employee name :";
	cin >> ws;
	getline(cin, name);
	e.setName(name);

	cout << "Enter employee password :";
	getline(cin, password);
	e.setPassword(password);

	cout << "Enter employee salary :";
	cin >> salary;
	e.setSalary(salary);

	e.setId(FilesHelper::getLast("lastIdEmployee.txt") + 1);
	admin->addEmployee(e);
}

void AdminManager::searchForEmployee(Admin* admin) {
	int id;
	cout << "Enter employee id :";
	cin >> id;
	Employee* e = admin->searchEmployee(id);
	if (e == nullptr) {
		cout << "No employee found with this ID.\n";
		return;
	}
	e->DisplayInfo();
	delete e;
}

void AdminManager::listAllEmployees(Admin* admin) {
	admin->listEmployee();
}

void AdminManager::editEmployeeInfo(Admin* admin) {
	int id;
	string name, password;
	double salary;

	cout << "Enter employee id :";
	cin >> id;
	Employee* e = admin->searchEmployee(id);
	if (e == nullptr) {
		cout << "No employee found with this ID.\n";
		return;
	}
	delete e;

	cout << "Enter new name :";
	cin >> ws;
	getline(cin, name);
	cout << "Enter new password :";
	getline(cin, password);
	cout << "Enter new salary :";
	cin >> salary;

	admin->editEmployee(id, name, password, salary);
}

Admin* AdminManager::login(int id, string password) {
	for (int i = 0; i < FilesHelper::Admins.size(); i++) {
		if (FilesHelper::Admins[i].getId() == id &&
			FilesHelper::Admins[i].getPassword() == password) {
			cout << "Login Successfully.\n";
			cout << "Welcome ," << FilesHelper::Admins[i].getName() << "\n";
			return &FilesHelper::Admins[i];
		}
	}
	return nullptr;
}

bool AdminManager::AdminOptions(Admin* admin) {
	printAdminMenu();
	cout << "Enter your choice:";
	int choice; cin >> choice;
	switch (choice) {
	case 1:  admin->DisplayInfo(); break;
	case 2:  EmployeeManager::newClient(admin); break;
	case 3:  EmployeeManager::searchForClient(admin); break;
	case 4:  EmployeeManager::listAllClients(admin); break;
	case 5:  EmployeeManager::editClientInfo(admin); break;
	case 6:  newEmployee(admin); break;
	case 7:  searchForEmployee(admin); break;
	case 8:  listAllEmployees(admin); break;
	case 9:  editEmployeeInfo(admin); break;
	case 10: updatePassword(admin); break;
	case 11: return false;
	default:
		cout << "Invalid choice.\n";
	}
	return true;
}
