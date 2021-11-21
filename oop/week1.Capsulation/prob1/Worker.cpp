#include "Worker.h"

void Worker::addNew()
{
    cout << "Ten: ";
    cin >> name;
    cout << "Tuoi: ";
    cin >> age;
    cout << "Gioi tinh (Nam:0 / Nu:1): ";
    cin >> gender;
    cout << "Que quan: ";
    cin.ignore(), getline(cin, hometown);
    cout << "Ngay cong: ";
    cin >> dayWorked;
    cout << "Xep hang: ";
    cin >> rank;
}
void Worker::getInfo()
{
    cout << "Ten: ";
    cout << name << endl;
    cout << "Tuoi: ";
    cout << age << endl;
    cout << "Gioi tinh(Nam:0 / Nu:1): ";
    gender ? (cout << "Nu\n") : (cout << "Nam\n");
    cout << "Que quan: ";
    cout << hometown << endl;
    cout << "Ngay cong: ";
    cout << dayWorked << endl;
    cout << "Xep hang: ";
    cout << rank << endl;
}
int Worker::getSalary()
{
    return 100000 * dayWorked;
}
int Worker::getDay()
{
    return dayWorked;
}