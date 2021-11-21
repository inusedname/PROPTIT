#include <bits/stdc++.h>

using namespace std;

class People
{
protected:
    string name;
    int age;
    string address;

public:
    People(){};
    void addNew();
    void getInfo();
};
class Students : public People
{
    int id;
    int math, physics, chemistry;

public:
    Students(){};
    void addNew();
    void getInfo();
    double gpa();
    int getID() { return id; }
};
class StudentManager
{
    vector<Students> students;

public:
    StudentManager(){};
    void addNew();
    void getInfo();
    void getGPA();
};
void People::addNew()
{
    cout << "Name: ", cin.ignore(), getline(cin, name);
    cout << "Age: ", cin >> age;
    cout << "Address: ", cin.ignore(), getline(cin, address);
}
void Students::addNew()
{
    People::addNew();
    cout << "ID: ", cin >> id;
    cout << "Toan - Ly - Hoa: ", cin >> math >> physics >> chemistry;
}
void People::getInfo()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Address: " << address << endl;
}
void Students::getInfo()
{
    cout << "ID: " << id << endl;
    People::getInfo();
    cout << "Toan - Ly - Hoa: " << math << " " << physics << " " << chemistry << endl;
}
double Students::gpa()
{
    return (math + physics + chemistry) / 3;
}
void StudentManager::addNew()
{
    int n;
    Students tmp;
    cout << "Nhap so luong hoc sinh muon them: ", cin >> n;
    for (int i = 0; i < n; i++)
    {
        tmp.addNew();
        students.push_back(tmp);
        cout << "Add Student Successfully\n";
    }
}
void StudentManager::getInfo()
{
    int id;
    cout << "Nhap ID hoc sinh muon in:", cin >> id;
    for (int i = 0; i < students.size(); i++)
    {
        if (id == students[i].getID())
        {
            students[i].getInfo();
            break;
        }
    }
}
void StudentManager::getGPA()
{
    int id;
    cout << "Nhap ID hoc sinh muon in: ", cin >> id;
    for (int i = 0; i < students.size(); i++)
    {
        if (id == students[i].getID())
        {
            cout << "GPA: " << students[i].gpa() << endl;
            break;
        }
    }
}
int main()
{
    int choice;
    StudentManager myStudent;
    while (1)
    {
        cout << "=================MENU================\n";
        cout << "1. Them moi hoc sinh\n";
        cout << "2. In thong tin hoc sinh\n";
        cout << "3. In GPA hoc sinh\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        if (!choice)
        {
            cout << "Chuong trinh ket thuc.";
            break;
        }
        cout << "=====================================\n";
        switch (choice)
        {
        case 1:
            myStudent.addNew();
            break;
        case 2:
            myStudent.getInfo();
            break;
        case 3:
            myStudent.getGPA();
            break;
        }
    }
}