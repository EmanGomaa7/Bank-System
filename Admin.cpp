#include"Admin.h"
#include"FilesHelper.h"
#include"FileManager.h"

    void Admin::addEmployee(Employee& employee) {
        cout << "=============Add=============\n";
        FileManager fm;
        fm.addEmployee(employee);
        cout << "Employee added successfully.\n";

    }

    Employee* Admin::searchEmployee(int id) {
        cout << "=============Search=============\n";

        if (id > 0 && id <= FilesHelper::Employees.size()) {
            Employee* employee = new Employee(FilesHelper::Employees[id - 1]);
            return employee;
        }
        return nullptr;

    }

    void Admin::editEmployee(int id, string name, string password, double salary) {
        cout << "=============Edit=============\n";
       
        if (id < 1 || id > FilesHelper::Employees.size()) {
            cout << "This id doesn't exist.\n";
            return;
        }

        FileManager fm;
        FilesHelper::Employees[id - 1].setId(id);
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

