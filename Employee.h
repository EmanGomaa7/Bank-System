#pragma once
#include<iostream>
#include<string>
#include"Validation.h"
#include"Person.h"
using namespace std;
class Employee : public Person {
private:
    double salary = 0.0;

    double enterSalary(double& salary) {
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

public:
    void setSalary(double salary) {
        this->salary = enterSalary(salary);
    }
    double getSalary() {
        return salary;
    }
    virtual void DisplayInfo() override {
        Person::DisplayInfo();
        cout << "Salary    : " << salary << "\n";
        cout << "==============================\n";
    }
};

