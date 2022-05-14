#include "Factory.h"
#include <algorithm> // sort
void Factory::addNewWorker()
{
    int n;
    cout << "Nhap so cong nhan muon them: ";
    cin >> n;
    Worker newWorker;
    for (int i = 0; i < n; i++)
    {
        cout << "Cong nhan thu " << i + 1 << ":\n";
        newWorker.addNew();
        worker.push_back(newWorker); // add
    }
}
long long Factory::sumWorkerSalary()
{
    long long sumSalary = 0;
    for (int i = 0; i < worker.size(); i++)
        sumSalary += worker[i].getSalary();
    return sumSalary;
}
void Factory::sortDescendingWorkerSalary()
{
    cout << "Sap xep cong nhan: Salary Descending\n";
    vector<Worker> tmp = worker;
    sort(tmp.begin(), tmp.end(), [](Worker x, Worker y)
         { return x.getSalary() > y.getSalary(); });
    for (int i = 0; i < tmp.size(); i++)
        cout << tmp[i].getSalary() << " ";
}
void Factory::sortDescendingWorkerDayWorked()
{
    cout << "Sap xep cong nhan: Day Worked Descending\n";
    vector<Worker> tmp = worker;
    sort(tmp.begin(), tmp.end(), [](Worker x, Worker y)
         { return x.getDay() > y.getDay(); });
    for (int i = 0; i < tmp.size(); i++)
        cout << tmp[i].getDay() << " ";
}
void Factory::officerInfo()
{
    officer.getInfo();
}
void Factory::workerInfo()
{
    for (int i = 0; i < worker.size(); i++)
        worker[i].getInfo();
}
void Factory::setOfficerInfo()
{
    officer.setInfo();
}