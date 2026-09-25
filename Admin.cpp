#include"Admin.h"
#include"FilesHelper.h"
#include"FileManager.h"

    void Admin::addEmployee(Employee& employee) {
        FileManager fm;
        fm.addEmployee(employee);
        cout << "Employee added successfully.\n";

    }

    Employee* Admin::searchEmployee(int id) {

        if (id > 0 && id <= FilesHelper::Employees.size()) {
            return &FilesHelper::Employees[id - 1];
        }
        return nullptr;

    }

    void Admin::editEmployee(int id, string name, string password, double salary) {
     
        FileManager fm;
        FilesHelper::Employees[id - 1].setId(id);
        cin.ignore();
        FilesHelper::Employees[id - 1].setName(name);
        FilesHelper::Employees[id - 1].setPassword(password);
        FilesHelper::Employees[id - 1].setSalary(salary);
        cout << "Employee edited successfully.\n";
        fm.updateEmployee();

    }

    void Admin::listEmployee() {
        cout << "=========Employees Info=========\n";

        for (int i = 0; i < FilesHelper::Employees.size();i++) {
            FilesHelper::Employees[i].DisplayInfo();
        }
    }

