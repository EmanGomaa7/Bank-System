#pragma once
#include "DataSourceInterface.h"
#include "Admin.h"

using namespace std;
class FileManager : public DataSourceInterface {
public:
	void addClient(Client client);
	void addEmployee(Employee employee);
	void addAdmin(Admin admin);
	void getAllClients();
	void getAllEmployees();
	void getAllAdmins();

	void removeAllClients();
	void removeAllEmployees();
	void removeAllAdmins();

	void updateClient();
	void updateEmployee();
	void updateAdmin();



};

