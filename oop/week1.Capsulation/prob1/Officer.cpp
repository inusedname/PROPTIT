#include "Officer.h"

void Officer::setInfo()
{
    cout << "Ten: ";
    cin >> name;
    cout << "Tuoi: ";
    cin >> age;
    cout << "Gioi tinh (Nam:0 / Nu:1): ";
    cin >> gender;
    cout << "Que quan: ";
    cin.ignore(), getline(cin, hometown);
    cout << "He so luong: ";
    cin >> salaryMultiplication;
}
int Officer::getSalary()
{
    return 3000000 * salaryMultiplication;
}
void Officer::getInfo()
{
    cout << "Ten: ";
    cout << name << endl;
    cout << "Tuoi: ";
    cout << age << endl;
    cout << "Gioi tinh (Nam:0 / Nu:1): ";
    gender ? (cout << "Nu\n") : (cout << "Nam\n");
    cout << "Que quan: ";
    cout << hometown << endl;
    cout << "He so luong: ";
    cout << salaryMultiplication << endl;
}