#include "class.h"
int main()
{
    int choice;
    Manager myPeople;
    while (1)
    {
        cout << "=================MENU================\n";
        cout << "1. Nhap thong tin nhan vien\n";
        cout << "2. In thong tin nhan vien (gom luong)\n";
        cout << "3. Tinh tong tien luong nhan vien\n";
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
            myPeople.addNew();
            break;
        case 2:
            myPeople.getInfo();
            break;
        case 3:
            myPeople.getAllSalary();
            break;
        }
    }
}