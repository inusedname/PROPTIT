#include "class.h"

void Ticket::newTicket()
{
    cout << "Destination: ", cin.ignore(), getline(cin, destination);
    cout << "Date: ", cin >> date;
    cout << "Price: ", cin >> price;
}
void Ticket::showTicket()
{
    cout << "Destination: " << destination << endl;
    cout << "Date: " << date << endl;
    cout << "Price: " << price << endl;
}
int Ticket::getPrice()
{
    return this->price;
}
void Person::newPerson()
{
    cout << "Name: ", cin.ignore(), getline(cin, name);
    cout << "Gender: ", cin >> gender;
    cout << "Age: ", cin >> age;
}
void Person::showPerson()
{
    cout << "Name: " << name << endl;
    cout << "Gender: " << gender << endl;
    cout << "Age: " << age << endl;
}
void Passenger::newPassenger()
{
    newPerson();
    ticket.newTicket();
    cout << "So luong ve: ", cin >> quantity;
    this->purchase = quantity * this->ticket.getPrice();
}
void Passenger::showPassenger()
{
    Person::showPerson();
    ticket.showTicket();
    cout << "So luong ve: " << quantity << endl;
    cout << "TONG TIEN: " << this->purchase << endl;
}
int Passenger::showPurchase()
{
    return this->purchase;
}
void Manager::newPassenger()
{
    int n;
    cout << "Nhap so luong: ", cin >> n;
    for (int i = 0; i < n; i++)
    {
        Passenger *tmp = new Passenger();
        tmp->newPassenger();
        passengers.push_back(tmp);
        cout << "Add passenger successfully\n\n";
    }
}
void Manager::showInfo()
{
    for (int i = 0; i < passengers.size(); i++)
        passengers[i]->showPassenger();
}
void Manager::sortByPurchase()
{
    vector<Passenger *> tmp = passengers;
    sort(tmp.begin(), tmp.end(), [](Passenger *x, Passenger *y)
         { return x->showPurchase() > y->showPurchase(); });
    for (int i = 0; i < tmp.size(); i++)
        tmp[i]->showPassenger();
}