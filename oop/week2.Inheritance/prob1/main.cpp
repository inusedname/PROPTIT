#include "class.h"

int main()
{
    int choice;
    Manager manager;
    while (1)
    {
        cout << "=================MENU================\n";
        cout << "1. Them moi nhan vien\n";
        cout << "2. Tim kiem nhan vien theo ten\n";
        cout << "3. Tinh tien luong nhan vien\n";
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
            manager.addNew();
            break;
        case 2:
            manager.searchByName();
            break;
        case 3:
            manager.calcSalary();
            break;
        }
    }
}