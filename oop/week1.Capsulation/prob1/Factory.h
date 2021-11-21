#pragma once
#include "Worker.h"
#include "Officer.h"

class Factory
{
private:
    Officer officer;
    vector<Worker> worker;

public:
    Factory(){};
    void setOfficerInfo();
    void addNewWorker();
    long long sumWorkerSalary();
    void sortDescendingWorkerSalary();
    void sortDescendingWorkerDayWorked();
    void officerInfo();
    void workerInfo();
};