#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Person
{
protected:
    string name;

public:
    void addNew();
    void getInfo();
    virtual int getSalary() = 0;
};

class Staff : public Person
{
    int basicSalary;
    int dayWorked;

public:
    void addNew();
    int getSalary();
};
class Worker : public Person
{
    int qty; //quantity
    int ppp; //price per product
public:
    void addNew();
    int getSalary();
};
class Manager
{
    vector<Person *> people;

public:
    void addNew();
    void getInfo();
    void getAllSalary();
};
