#include "class.h"

void Student::setID()
{
    cout << "Student ID: ", cin >> ID;
}
void Student::setName()
{
    cout << "Name: ", cin.ignore(), getline(cin, name);
}
void Student::setBirth()
{
    cout << "Birth: ", cin >> birth;
}
void Student::setGender()
{
    cout << "Gender: ", cin >> gender;
}
void Student::setClass()
{
    cout << "Class: ", cin >> classroom;
}
void Student::setInfo()
{
    setID();
    setName();
    setBirth();
    setGender();
    setClass();
}
void Student::getInfo()
{
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Birth: " << birth << endl;
    cout << "Gender: " << gender << endl;
    cout << "Class: " << classroom << endl;
}
string Student::getID()
{
    return ID;
}
string Student::getName()
{
    return name;
}
bool operator<(Student x, Student y)
{
    return x.name < y.name;
}
void School::addStudent()
{
    Student tmp;
    char choice = 'c';
    while (choice == 'c')
    {
        tmp.setInfo();
        cout << "Add Student Successfully\n";
        students.push_back(tmp);
        cout << "Add more ? (c to Yes, k to No): ", cin.ignore(), cin >> choice;
    }
    cout << "Add Students Complete\n";
}
void School::rmStudent()
{
    bool flag = 0;
    string id;
    cout << "Modify Student ID: ", cin >> id;
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getID() == id)
        {
            flag = 1;
            students.erase(students.begin() + i);
            cout << "Remove Student Succesfully\n";
            break;
        }
    }
    if (!flag)
        cout << "Not found!\n";
}
void School::modStudent()
{
    bool flag = 0;
    string id;
    cout << "Modify Student ID: ", cin >> id;
    int choice;
    cout << "Which property to modify:\n"
         << "1. ID\n"
         << "2. Name\n"
         << "3. Birth\n"
         << "4. Gender\n"
         << "5. Class\n";
    cin >> choice;
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getID() == id)
        {
            flag = 1;
            switch (choice)
            {
            case 1:
                students[i].setID();
                cout << "Change ID Successfully\n";
                break;
            case 2:
                students[i].setName();
                cout << "Change Name Successfully\n";
                break;
            case 3:
                students[i].setBirth();
                cout << "Change Birth Successfully\n";

                break;
            case 4:
                students[i].setGender();
                cout << "Change Gender Successfully\n";

                break;
            case 5:
                students[i].setClass();
                cout << "Change Class Successfully\n";
                break;
            }
            break;
        }
    }
    if (!flag)
        cout << "Not found!\n";
}
void School::showAll()
{
    for (int i = 0; i < students.size(); i++)
        students[i].getInfo();
}
void School::heapSort()
{
}
void School::sortbyName()
{
    heapSort();
    cout << "Sort By Name Successfully\n";
}
int School::binarySearchbyName(string target)
{
    heapSort();
    int l = 0, r = students.size() - 1, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (target == students[m].getName())
            return m;
        else if (target > students[m].getName())
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
void School::searchByName()
{
    string target;
    cout << "Search Name: ", cin.ignore(), getline(cin, target);
    int posi = binarySearchbyName(target);
    if (posi == -1)
    {
        cout << "Not found.\n";
    }
    else
    {
        cout << "Found.\n";
        students[posi].getInfo();
    }
}