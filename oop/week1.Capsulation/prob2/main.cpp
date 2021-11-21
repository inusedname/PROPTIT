#include "class.h"

int main()
{
    Manager mySchool;
    int choice;
    while (1)
    {
        cout << "=================MENU================\n";
        cout << "1. Them giao vien\n";
        cout << "2. Them hoc sinh\n";
        cout << "3. Tao kip hoc\n";
        cout << "4. Sua giao vien\n";
        cout << "5. Sua hoc sinh\n";
        cout << "6. In danh sach giao vien\n";
        cout << "7. In danh sach hoc sinh\n";
        cout << "8. In thoi khoa bieu hoc sinh\n";
        cout << "9. In lich day cua giao vien\n";
        cout << "10. Luong cua giao vien\n";
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
            mySchool.addTeacher();
            break;
        case 2:
            mySchool.addStudent();
            break;
        case 3:
            mySchool.addClassroom();
            break;
        case 4:
            mySchool.editTeacher();
            break;
        case 5:
            mySchool.editStudent();
            break;
        case 6:
            mySchool.showTeacherList();
            break;
        case 7:
            mySchool.showStudentList();
            break;
        case 8:
            mySchool.showScheduleOfStudent();
            break;
        case 9:
            mySchool.showScheduleOfTeacher();
            break;
        case 10:
            mySchool.getWageOfTeacher();
            break;
        }
    }
}