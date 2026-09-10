#pragma once
#include <iostream>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "DataSourceInterface.h"
#include "FilesHelper.h"

using namespace std;
class FileManager : public DataSourceInterface {
public:
	void addClient(Client client) {
		
	}
	void addEmployee(Employee employee){
		
	}
    void addAdmin(Admin admin) {
	
	}

	void getAllClients(){
		//fetchClients()
	}
	void getAllEmployees(){
	    //fetchEmployees()
	}
	void getAllAdmins() {
	    //fetchAdmins()
	}
	void removeAllClients(){
		//clearFile(Clients,lastIdClient)
	}
	void removeAllEmployees() {
		//clearFile(Employees,lastIdEmployee)
	}
	void removeAllAdmins() {
		//clearFile(Admins,lastIdAdmin)
	}
	void updateClint(){
		
	}
	void updateEmployee(){}
	void updteAdmin(){}


};

