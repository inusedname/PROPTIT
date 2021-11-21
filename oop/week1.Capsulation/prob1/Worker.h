#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Worker
{
public:
    string name;
    int age;
    bool gender;
    string hometown;
    int dayWorked;
    int rank;

public:
    Worker(){};
    void addNew();
    void getInfo();
    int getDay();
    int getSalary();
};