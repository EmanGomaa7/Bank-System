#pragma once
#include<iostream>
#include<string>
#include"Validation.h"
#include"Employee.h"
using namespace std;
class Admin : public Employee {
public:
    void DisplayInfo() override {
        Employee::DisplayInfo();
    }
};

