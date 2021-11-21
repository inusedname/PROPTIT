#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
class Ticket
{
    string destination;
    string date;
    int price;

public:
    Ticket(){};
    ~Ticket(){};
    void newTicket();
    void showTicket();
    int getPrice();
};
class Person
{
protected:
    string name;
    string gender;
    int age;

public:
    Person(){};
    ~Person(){};
    void newPerson();
    void showPerson();
};
class Passenger : public Person
{
    int quantity;
    Ticket ticket;
    int purchase;

public:
    Passenger(){};
    void newPassenger();
    void showPassenger();
    int showPurchase();
};
class Manager
{
    vector<Passenger *> passengers;

public:
    void newPassenger();
    void showInfo();
    void sortByPurchase();
};