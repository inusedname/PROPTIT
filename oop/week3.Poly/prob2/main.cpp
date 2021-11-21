#include "class.h"

int main()
{
    int choice;
    Manager manager;
    while (1)
    {
        cout << "=================MENU================\n";
        cout << "1. Them khach hang\n";
        cout << "2. In thong tin khach hang + tong tien phai tra\n";
        cout << "3. Sap xep theo tien phai tra\n";
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
            manager.newPassenger();
            break;
        case 2:
            manager.showInfo();
            break;
        case 3:
            manager.sortByPurchase();
            break;
        }
    }
}