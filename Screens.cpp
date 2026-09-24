#include "Screens.h"
#include <string>
#include <windows.h>
#include "Client.h"
#include "ClientManger.h"
#include "FilesHelper.h"
#include "EmployeeManager.h"
#include "AdminManager.h"

void Screens::bankName(){
	cout << " ________________________________________________________\n";
	cout << "|                                                        |\n";
	cout << "| ******    *****  *     *  *     *   *****    *****     |\n";
	cout << "| *     *  *     * *     *  **    *  *     *  *     *    |\n";
	cout << "| *     *  *     * *     *  * *   *  *     *  *     *    |\n";
	cout << "| ******   ******* *  *  *  *  *  *  *******  *     *    |\n";
	cout << "| *   *    *     * *  *  *  *   * *  *     *  *   * *    |\n";
	cout << "| *    *   *     * ** * **  *    **  *     *  *    *     |\n";
	cout << "| *     *  *     * *     *  *     *  *     *   **** *    |\n";
	cout << "|                                                        |\n";
	cout << "|_________With Rawnaq Bank, your money is safe___________|\n\n";

	Sleep(700);

}
void Screens::welcome(){
	cout << " *     * ******* *      ****** ****** *     * *******              \n";
	cout << " *     * *       *      *      *    * **   ** *                    \n";
	cout << " *     * *       *      *      *    * *  *  * *                    \n ";
	cout << "*  *  * ******* *      *      *    * *  *  * *******     *  ***   \n";
	cout << " *  *  * *       *      *      *    * *  *  * *          *** * *   \n";
	cout << " ** * ** *       *      *      *    * *     * *           *  * *   \n";
	cout << " *     * ******* ****** ****** ****** *     * *******     ** *** ...... \n\n";
	Sleep(700);
}
void Screens::loginOptions(){
	cout << "=================LOGIN==============\n";
	cout << "Login As :\n";
	cout << "1.Client\n";
	cout << "2.Employee\n";
	cout << "3.Admin\n\n";
}
int Screens::loginAs(){
	cout << "Enter your choice :";
	int choice; cin >> choice;
	if (choice < 1 || choice > 3) {
		cout << "Invalid choice.\n";
		loginAs();
	}
	return choice;
}
void Screens::invalid(int choice) {
	cout << "Incorrect id or password\n";
	loginScreen(choice);
}
void Screens::logout(){
	Screens::loginOptions();
	Screens::loginScreen(Screens::loginAs());
}
void Screens::loginScreen(int choice){
	cout << "Enter the id :";
	int id; cin >> id;
	cout << "Enter the password :";
	string password;
	cin.ignore();getline(cin, password);

	switch (choice) {
	case 1: {
		Client* client = ClientManger::login(id, password);
		if (client == nullptr) {
			Screens::invalid(choice);
		}
		else {
			bool flag = true;
			while (flag) {
				flag = ClientManger::clientOptions(client);
			}
			Screens::logout();
		}
		break;
	}
	case 2: {
		Employee* employee = EmployeeManager::login(id, password);
		if (employee == nullptr) {
			Screens::invalid(choice);
		}
		else {
			bool flag = true;
			while (flag) {
				flag = EmployeeManager::employeeOptions(employee);
			}
			Screens::logout();
		}
		break;
	}
	case 3: {
		Admin* admin = AdminManager::login(id, password);
		if (admin == nullptr) {
			Screens::invalid(choice);
		}
		else {
			bool flag = true;
			while (flag) {
				flag = AdminManager::AdminOptions(admin);
			}
			Screens::logout();
		}
		break;
	}
	}

}
void Screens::runApp(){
	FilesHelper::fetchClients();
	FilesHelper::fetchEmployees();
	FilesHelper::fetchAdmins();

	Screens::welcome();
	Screens::bankName();

	Screens::loginOptions();
    Screens::loginScreen(Screens::loginAs());
}
