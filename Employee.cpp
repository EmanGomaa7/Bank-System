#include"Employee.h"
#include"Validation.h"
#include"FileManager.h"
#include "FilesHelper.h"
#include"Person.h"

    double Employee::enterSalary(double& salary) {
        bool isValid = false;
        while (!isValid) {
            if (!Validation::validSalary(salary)) {
                cout << "Please try again.\n";
                cout << "Enter your salary : ";
                cin >> salary;
            }
            else isValid = true;
        }
        return salary;
    }

    void Employee::setSalary(double salary) {
        this->salary = enterSalary(salary);
    }
    double Employee::getSalary() {
        return salary;
    }

    void Employee::DisplayInfo()  {
        Person::DisplayInfo();
        cout << "Salary    : " << salary << "\n";
        cout << "==============================\n";
    }

    void Employee::addClient(Client& client) {
        cout << "============Add===========\n";
        FileManager fm;
        fm.addClient(client);
        cout << "Client added successfully.\n";
    }
    Client* Employee::searchClient(int id) {
        cout << "==========Search==========\n";
        if (id > 0 && id <= FilesHelper::Clients.size()) {
            Client* client = new Client(FilesHelper::Clients[id - 1]);
            return client;
        }
        return nullptr;

    }
    void Employee::listClient() { 
        cout << "=========Clients Info=========\n";
        for (int i = 0; i < FilesHelper::Clients.size();i++) {
             FilesHelper::Clients[i].DisplayInfo();
        }

    }
    void Employee::editClient(int id, string name, string password, double balance) {
        cout << "===========Edit===========\n";

        if (id < 1 || id > FilesHelper::Clients.size()) {
            cout << "This id doesn't exist.\n";
            return;
        }
        FileManager fm;
        FilesHelper::Clients[id - 1].setId(id);
        FilesHelper::Clients[id - 1].setName(name);
        FilesHelper::Clients[id - 1].setPassword(password);
        FilesHelper::Clients[id - 1].setBalance(balance);
        cout << "Client edited successfully.\n";
        fm.updateClient();
    }

