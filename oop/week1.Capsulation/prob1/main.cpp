#include "Factory.h"
int main()
{
    int choice;
    Factory myFactory;
    while (1)
    {
        cout << "=================MENU================\n";
        cout << "1. Nhap thong tin can bo\n";
        cout << "2. Them moi mot cong nhan\n";
        cout << "3. Tinh tong tien luong cua cac cong nhan\n";
        cout << "4. Sap xep lai thu tu cong nhan theo luong giam dan\n";
        cout << "5. Sap xep lai thu tu cong nhan theo gio lam viec giam dan\n";
        cout << "6. In thong tin can bo\n";
        cout << "7. In thong tin tat ca cong nhan\n";
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
            myFactory.setOfficerInfo();
            break;
        case 2:
            myFactory.addNewWorker();
            break;
        case 3:
            cout << myFactory.sumWorkerSalary() << endl;
            break;
        case 4:
            myFactory.sortDescendingWorkerSalary();
            break;
        case 5:
            myFactory.sortDescendingWorkerDayWorked();
            break;
        case 6:
            myFactory.officerInfo();
            break;
        case 7:
            myFactory.workerInfo();
            break;
        }
    }
}