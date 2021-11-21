#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Officer
{
private:
    string name;
    int age;
    bool gender;
    string hometown;
    float salaryMultiplication;

public:
    Officer(){};
    void setInfo();
    void getInfo();
    int getSalary();
};