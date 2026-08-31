#pragma once
#include<iostream>
#include<string>
#include"Validation.h"
#include"Employee.h"
using namespace std;
class Admin : public Employee {
public:
    virtual void DisplayInfo() override {
        Employee::DisplayInfo();
    }
};

