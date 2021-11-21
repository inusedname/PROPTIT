#include "class.h"

int Worker::nWorker = 0;
int Architect::nArchitect = 0;
int Guard::nGuard = 0;

void HumanResource::addNew()
{
    cout << "Name: ", cin.ignore(), getline(cin, name);
    cout << "Age: ", cin >> age;
    cout << "Gender: ", cin >> gender;
    cout << "Address: ", cin.ignore(), getline(cin, address);
    cout << "Telephone: ", cin >> telephone;
    cout << "Hometown: ", cin.ignore(), getline(cin, hometown);
    cout << "Multiplication of Salary: ", cin >> salaryMultiply;
    cout << "Day Worked: ", cin >> dayWorked;
}
string HumanResource::getName()
{
    return name;
}
double HumanResource::getSalary()
{
    return dayWorked * salaryMultiply;
}
void HumanResource::setID(int n)
{
    if (n < 100)
        ID += "0";
    if (n < 10)
        ID += "0";
    ID += to_string(n);
}
string HumanResource::getID()
{
    return ID;
}
void HumanResource::getDetail()
{
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Address: " << address << endl;
    cout << "Telephone: " << telephone << endl;
    cout << "Hometown: " << hometown << endl;
    cout << "Multiplication of Salary: " << salaryMultiply << endl;
    cout << "Day Worked: " << dayWorked << endl;
}
double Worker::getSalary()
{
    return HumanResource::getSalary() * level;
}
void Worker::addNew()
{
    HumanResource::addNew();
    cout << "Level of worker: ", cin >> level;
    setID(nWorker);
}
void Worker::getDetail()
{
    HumanResource::getDetail();
    cout << "Level of worker: " << level << endl;
}
double Architect::getSalary()
{
    return HumanResource::getSalary() * expYear;
}
void Architect::addNew()
{
    HumanResource::addNew();
    cout << "Year experienced: ", cin >> expYear;
    setID(nArchitect);
}
void Architect::getDetail()
{
    HumanResource::getDetail();
    cout << "Year experienced: " << expYear << endl;
}

void Guard::addNew()
{
    HumanResource::addNew();
    cout << "Working position to be binded: ", cin >> position;
    setID(nGuard);
}
void Guard::getDetail()
{
    HumanResource::getDetail();
    cout << "Position: " << position << endl;
}
void Manager::addNew()
{
    int choice;
    cout << "Type of staff:\n"
         << "1.Worker\n"
         << "2.Architect\n"
         << "3.Guard\n";
    cout << "Your choice: ", cin >> choice;
    switch (choice)
    {
    case 1:
    {
        Worker tmp;
        tmp.addNew();
        worker.push_back(tmp);
        cout << "Add Worker Successfully!\n";
        break;
    }
    case 2:
    {
        Architect tmp;
        tmp.addNew();
        architect.push_back(tmp);
        cout << "Add Architect Successfully!\n";
        break;
    }
    case 3:
    {
        Guard tmp;
        tmp.addNew();
        guard.push_back(tmp);
        cout << "Add Guard Successfully!\n";
        break;
    }
    }
}
void Manager::searchByName()
{
    string target;
    cout << "Search: ", cin.ignore(), getline(cin, target);
    vector<pair<string, string>> ans;
    for (int i = 0; i < worker.size(); i++)
    {
        string tmp = worker[i].getName();
        if (tmp.find(target) != string::npos)
            ans.push_back({worker[i].getID(), tmp});
    }
    for (int i = 0; i < architect.size(); i++)
    {
        string tmp = architect[i].getName();
        if (tmp.find(target) != string::npos)
            ans.push_back({architect[i].getID(), tmp});
    }
    for (int i = 0; i < guard.size(); i++)
    {
        string tmp = guard[i].getName();
        if (tmp.find(target) != string::npos)
            ans.push_back({guard[i].getID(), tmp});
    }
    cout << ans.size() << " matching.\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " : " << ans[i].second << "\n";

    int choice;
    cout << "1. View details\n"
         << "0. Exit\n"
         << "Your choice: ";
    cin >> choice;
    if (!choice)
        return;
    cout << "View detail of #?: ", cin >> choice;
    choice--;
    target = ans[choice].first.substr(0, 2);
    if (target == "CN")
    {
        for (int i = 0; i < worker.size(); i++)
            if (worker[i].getID() == ans[choice].first)
            {
                worker[i].getDetail();
                break;
            }
    }
    else if (target == "KS")
    {
        for (int i = 0; i < architect.size(); i++)
            if (architect[i].getID() == ans[choice].first)
            {
                architect[i].getDetail();
                break;
            }
    }
    else
    {
        for (int i = 0; i < guard.size(); i++)
            if (guard[i].getID() == ans[choice].first)
            {
                guard[i].getDetail();
                break;
            }
    }
}
void Manager::calcSalary()
{
    string target;
    string id;
    cout << "Staff Type (worker/architect/guard): ", cin >> target;
    cout << "ID: ", cin >> id;
    if (target == "worker")
    {
        for (int i = 0; i < worker.size(); i++)
        {
            if (id == worker[i].getID())
            {
                cout << id << " : ";
                cout << worker[i].getSalary();
                break;
            }
        }
    }
    else if (target == "architect")
    {
        for (int i = 0; i < architect.size(); i++)
        {
            if (id == architect[i].getID())
            {
                cout << id << " : ";
                cout << architect[i].getSalary();
                break;
            }
        }
    }
    else if (target == "guard")
    {
        for (int i = 0; i < architect.size(); i++)
        {
            if (id == architect[i].getID())
            {
                cout << id << " : ";
                cout << architect[i].getSalary();
                break;
            }
        }
    }
    else
        cout << "Wrong Input";
    cout << endl;
}