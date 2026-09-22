#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Validation.h"
#include "FilesHelper.h"

using namespace std;
    
int main(){
	FilesHelper::fetchClients();
	FilesHelper::fetchEmployees();
	FilesHelper::fetchAdmins();


	Client c;
	c.setName("Eman");
	c.setId(10);
	c.setPassword("Eman123!@@");
	c.setBalance(123456);
	FilesHelper::saveClient(c);
}