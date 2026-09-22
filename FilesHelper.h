#pragma once
#include <fstream>
#include <vector>
#include "Admin.h"
using namespace std;
    
class FilesHelper {
	//opening mode
	//ios::app 
	//ios::trunc(defult) 
	//ofstream out("filename",ios...)
	//odj.close()
	//=============================================
	//ifstream in ;
	//in.open();
	//=======
	//eof() if end of file return true
public:
	static vector <Client> Clients;
	static vector <Employee> Employees;
	static vector <Admin> Admins;
	
	// ofstream from prog to file
	// id#name#bal#pass



	static void saveLast(string fileName, int id);
	static int getLast(string fileName);

	static void saveClient(Client client);
	static void saveEmployee(string fileName, string lastIdFile, Employee employee);

	static void fetchClients();
	static void fetchEmployees();
	static void fetchAdmins();

	static void clearFile(string fileName, string lastIdFile);



};

