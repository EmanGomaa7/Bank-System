#pragma once
#include "Admin.h"
using namespace std;
class DataSourceInterface
{
public:
	virtual void addClient(Client client) = 0;
	virtual void addEmployee(Employee employee) = 0;
	virtual void addAdmin(Admin admin) = 0;
	virtual void getAllClients() = 0;
	virtual void getAllEmployees() = 0;
	virtual void getAllAdmins() = 0;
	virtual void removeAllClients() = 0;
	virtual void removeAllEmployees() = 0;
	virtual void removeAllAdmins() = 0;

};

