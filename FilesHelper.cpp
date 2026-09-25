#include "FilesHelper.h"
#include "Parser.h"

vector <Client> FilesHelper::Clients;
vector <Employee> FilesHelper::Employees;
vector <Admin> FilesHelper::Admins;

void FilesHelper::saveLast(string fileName, int id) {
	ofstream saveID(fileName);
	saveID << id;
	saveID.close();
}
int FilesHelper::getLast(string fileName) {
	int lastId;
	ifstream getId(fileName);
	getId >> lastId;
	getId.close();
	return lastId;
}

void FilesHelper::saveClient(Client client) {
	ofstream save("Clients.txt", ios::app);
	int id = FilesHelper::getLast("lastIdClient.txt") + 1;
	save << id << '-' << client.getName() << '-' << client.getBalance() << '-' << client.getPassword() << endl;
	save.close();
	ofstream saveID("lastIdClient.txt");
	saveID << id ;
	saveID.close();

}
void FilesHelper::saveEmployee(string fileName, string lastIdFile, Employee employee) {
	ofstream save(fileName, ios::app);
	int id = FilesHelper::getLast(lastIdFile) + 1;
	save << id << '-' << employee.getName() << '-' << employee.getSalary() << '-' << employee.getPassword() << endl;
	save.close();
	ofstream saveID(lastIdFile);
	saveID << id ;
	saveID.close();
}

void FilesHelper::fetchClients() {
	ifstream fetch("Clients.txt");
	string line;
	while (getline(fetch , line)) {
		FilesHelper::Clients.push_back(Parser::parseToClient(line));
	}
	fetch.close();
}
void FilesHelper::fetchEmployees() {
	ifstream fetch("Employees.txt");
	string line;
	while (getline(fetch, line)) {
		FilesHelper::Employees.push_back(Parser::parseToEmployee(line));
	}
	fetch.close();

}
void FilesHelper::fetchAdmins() {
	ifstream fetch("Admins.txt");
	string line;
	while (getline(fetch, line)) {
		FilesHelper::Admins.push_back(Parser::parseToAdmin(line));
	}
	fetch.close();

}

void FilesHelper::clearFile(string fileName, string lastIdFile) {
	ofstream clearID(lastIdFile);
	clearID << 0;
	clearID.close();
	ofstream clear(fileName);
	clear.close();
}







