#pragma once
#include<iostream>
#include"Employee.h"
#include<string>

using namespace std;


class Admin : public Employee {
public:
    void addEmployee(Employee& employee);

    Employee* searchEmployee(int id);
     
    void editEmployee(int id, string name, string password, double salary);

    void listEmployee();
};

