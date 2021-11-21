#include "class.h"

void Person::addNew()
{
    cout << "Name: ", cin.ignore(), getline(cin, this->name);
}
void Person::getInfo()
{
    cout << "Name: " << name << endl;
    cout << "Salary: " << this->getSalary() << endl;
}
void Staff::addNew()
{
    Person::addNew();
    cout << "Luong co ban: ", cin >> basicSalary;
    cout << "Ngay lam viec: ", cin >> dayWorked;
}
int Staff::getSalary()
{
    return this->basicSalary * this->dayWorked;
}
void Worker::addNew()
{
    Person::addNew();
    cout << "So san pham lam duoc: ", cin >> qty;
    cout << "Tien cong / sp: ", cin >> ppp;
}
int Worker::getSalary()
{
    return this->qty * this->ppp;
}
void Manager::addNew()
{
    int choice;
    cout << "[1]. Nhan vien\n[2]. Cong nhan\nYour choice: ";
    cin >> choice;
    if (choice == 1)
    {
        Staff *tmp = new Staff;
        tmp->addNew();
        people.push_back(tmp);
        cout << "Add Staff Successfully\n";
    }
    else
    {
        Worker *tmp = new Worker;
        tmp->addNew();
        people.push_back(tmp);
        cout << "Add Worker Successfully\n";
    }
}
void Manager::getInfo()
{
    int id;
    cout << "ID Number: ", cin >> id;
    people[id - 1]->getInfo();
}
void Manager::getAllSalary()
{
    int sum = 0;
    for (auto &&mem : people)
    {
        sum += mem->getSalary();
    }
    cout << "Total : " << sum << endl;
}