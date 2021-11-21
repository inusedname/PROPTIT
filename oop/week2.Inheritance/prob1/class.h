#include <iostream>
#include <string>
#include <vector>
#define endl "\n"
using namespace std;

class HumanResource
{
protected:
    string name;
    int age;
    string gender;
    string address;
    string telephone;
    string hometown;
    double salaryMultiply;
    int dayWorked;
    string ID;

public:
    void addNew();
    void setID(int n);
    string getName();
    string getID();
    double getSalary();
    void getDetail();
};

class Worker : public HumanResource
{
    int level;

public:
    static int nWorker;
    Worker()
    {
        nWorker++;
        ID = "CN";
    }
    double getSalary();
    void addNew();
    void getDetail();
};

class Architect : public HumanResource
{
    string specialize;
    int expYear;

public:
    static int nArchitect;
    Architect()
    {
        nArchitect++;
        ID = "KS";
    }
    double getSalary();
    void addNew();
    void getDetail();
};

class Guard : public HumanResource
{
    string position;

public:
    static int nGuard;
    Guard()
    {
        nGuard++;
        ID = "BV";
    }
    void addNew();
    void getDetail();
};

class Manager
{
    vector<Worker> worker;
    vector<Architect> architect;
    vector<Guard> guard;

public:
    void addNew();
    void searchByName();
    void calcSalary();
};