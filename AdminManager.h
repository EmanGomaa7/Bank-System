#pragma once
#include "Admin.h"
using namespace std;

class AdminManager {
public:
	static void printAdminMenu();
	static void updatePassword(Admin* admin);
	static void newEmployee(Admin* admin);
	static void searchForEmployee(Admin* admin);
	static void listAllEmployees(Admin* admin);
	static void editEmployeeInfo(Admin* admin);
	static Admin* login(int id, string password);
	static bool AdminOptions(Admin* admin);
};
