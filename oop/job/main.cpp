#include "class.h"
int main()
{
    int choice;
    School myStudent;
    while (1)
    {
        cout << "=================MENU================\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Xoa sinh vien\n";
        cout << "3. Sua doi thong tin sinh vien\n";
        cout << "4. Sap xep danh sach sinh vien theo ho ten\n";
        cout << "5. Hien thi toan bo danh sach sinh vien\n";
        cout << "6. Tim kiem sinh vien theo ho ten\n";
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
            myStudent.addStudent();
            break;
        case 2:
            myStudent.rmStudent();
            break;
        case 3:
            myStudent.modStudent();
            break;
        case 4:
            myStudent.sortbyName();
            break;
        case 5:
            myStudent.showAll();
            break;
        case 6:
            myStudent.searchByName();
            break;
        }
    }
}