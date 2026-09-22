#pragma once
#include"Client.h"

using namespace std;

class Employee : public Person {
private:
    double salary = 0.0;

    double enterSalary(double& salary);

public:
    void setSalary(double salary);
    double getSalary();
    virtual void DisplayInfo() override;
    void addClient(Client& client);
    Client* searchClient(int id);
    void listClient();
    void editClient(int id, string name, string password, double balance);
};

