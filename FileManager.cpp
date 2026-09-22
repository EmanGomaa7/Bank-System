#include "FileManager.h"
#include "FilesHelper.h"
#include <fstream>

void FileManager::addClient(Client client) {
	FilesHelper::Clients.push_back(client);
	FilesHelper::saveClient(client);
}
void FileManager::addEmployee(Employee employee) {
	FilesHelper::Employees.push_back(employee);
	FilesHelper::saveEmployee("Employees.txt", "lastIdEmployee.txt", employee);
}
void FileManager::addAdmin(Admin admin) {
	FilesHelper::Admins.push_back(admin);
	FilesHelper::saveEmployee("Admins.txt", "lastIdAdmin.txt", admin);
}

void FileManager::getAllClients() {
	FilesHelper::fetchClients();
}
void FileManager::getAllEmployees() {
	FilesHelper::fetchEmployees();
}
void FileManager::getAllAdmins() {
	FilesHelper::fetchAdmins();
}

void FileManager::removeAllClients() {
	FilesHelper::Clients.clear();
	FilesHelper::clearFile("Clients.txt", "lastIdClient.txt");
}
void FileManager::removeAllEmployees() {
	FilesHelper::Employees.clear();
	FilesHelper::clearFile("Employees.txt", "lastIdEmployee.txt");
}
void FileManager::removeAllAdmins() {
	FilesHelper::Admins.clear();
	FilesHelper::clearFile("Admins.txt", "lastIdAdmin.txt");
}

void FileManager::updateClient() {
	ofstream update("Clients.txt");
	for (int i = 0; i < FilesHelper::Clients.size(); i++) {
		string line = to_string(FilesHelper::Clients[i].getId()) + '-' + FilesHelper::Clients[i].getName() + '-' + to_string(FilesHelper::Clients[i].getBalance()) + '-' + FilesHelper::Clients[i].getPassword();
		update << line << endl;
	}
	update.close();

}
void FileManager::updateEmployee() {
	ofstream update("Employees.txt");
	for (int i = 0; i < FilesHelper::Employees.size(); i++) {
		string line = to_string(FilesHelper::Employees[i].getId()) + '-' + FilesHelper::Employees[i].getName() + '-' + to_string(FilesHelper::Employees[i].getSalary()) + '-' + FilesHelper::Employees[i].getPassword();
		update << line << endl;
	}
	update.close();
}
void FileManager::updateAdmin() {
	ofstream update("Admins.txt");
	for (int i = 0; i < FilesHelper::Admins.size(); i++) {
		string line = to_string(FilesHelper::Admins[i].getId()) + '-' + FilesHelper::Admins[i].getName() + '-' + to_string(FilesHelper::Admins[i].getSalary()) + '-' + FilesHelper::Admins[i].getPassword();
		update << line << endl;
	}
	update.close();
}








