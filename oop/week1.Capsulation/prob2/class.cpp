#include "class.h"

int Classroom::NUM_CLASSROOM = 0;
int Student::NUM_STUDENT = 0;
int Teacher::NUM_TEACHER = 0;

string Address::getHometown() { return hometown; }
string Address::getCurrentAdd() { return currentAdd; }
void Address::setHometown(string hometown) { this->hometown = hometown; }
void Address::setCurrentAdd(string currentadd) { this->currentAdd = currentadd; }

pair<int, int> Time::showTime() { return make_pair(start, end); }
void Time::setTime(int start, int end) { this->start = start, this->end = end; }

void Transcript::setTranscript(double history, double english, double math)
{
    this->history = history;
    this->english = english;
    this->math = math;
}
void Transcript::getTranscript()
{
    cout << "History: " << history << " "
         << "English: " << english << " "
         << "Math: " << math << endl;
}

void Student::changeName()
{
    cout << "Ten: ";
    cin.ignore();
    getline(cin, name);
}
void Student::changeID()
{
    cout << "id: ";
    cin >> id;
}
void Student::changeAddress()
{
    string tmp;
    cout << "Que quan: ";
    cin.ignore();
    getline(cin, tmp);
    address.setHometown(tmp);
    cout << "Dia chi thuong tru: ";
    getline(cin, tmp);
    address.setCurrentAdd(tmp);
}
void Student::changeResult()
{
    cout << "Diem Lich Su - Tieng Anh - Toan: ";
    double history, english, math;
    cin >> history >> english >> math;
    result.setTranscript(history, english, math);
}
int Student::getID()
{
    return id;
}
void Student::addStudent()
{
    changeName();
    changeID();
    changeAddress();
    changeResult();
}
void Student::showStudent()
{
    cout << "Ten: " << name << endl;
    cout << "id: " << id << endl;
    cout << "Que quan: " << address.getHometown() << endl;
    cout << "Dia chi thuong tru: " << address.getCurrentAdd() << endl;
    result.getTranscript();
}
vector<int> Student::getSchedule()
{
    return classID;
}
int Teacher::getID()
{
    return id;
}
int Teacher::getSalary()
{
    return salary;
}
void Teacher::changeName()
{
    cout << "Ten: ";
    cin.ignore();
    getline(cin, name);
}
void Teacher::changeID()
{
    cout << "id: ";
    cin >> id;
}
void Teacher::changeAddress()
{
    string tmp;
    cout << "Que quan: ";
    cin.ignore();
    getline(cin, tmp);
    address.setHometown(tmp);
    cout << "Dia chi thuong tru: ";
    getline(cin, tmp);
    address.setCurrentAdd(tmp);
}
void Teacher::changeSalary()
{
    cout << "Muc luong: ";
    cin >> salary;
}
void Teacher::addTeacher()
{
    changeName();
    changeID();
    changeAddress();
    changeSalary();
}
void Teacher::showTeacher()
{
    cout << "Ten: " << name << endl;
    cout << "id: " << id << endl;
    cout << "Que quan: " << address.getHometown() << endl;
    cout << "Dia chi thuong tru: " << address.getCurrentAdd() << endl;
    cout << "Luong: " << salary << endl;
}
vector<int> Teacher::getSchedule()
{
    return classID;
}
void Classroom::sayTime()
{
    cout << time.showTime().first << "h - " << time.showTime().second << "h";
}
int Classroom::getID()
{
    return id;
}
void Classroom::setTeacher(int idTeacher)
{
    this->idteacher = idteacher;
}
vector<Student> Manager::getStudent()
{
    return student;
}
void Student::editSchedule(int id)
{
    classID.push_back(id);
}
void Teacher::editSchedule(int id)
{
    classID.push_back(id);
}
void Classroom::setStudent(vector<Student> &all)
{
    cout << "Nhap so luong hoc sinh muon them: ";
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        bool flag = 0;
        cout << "Nhap id hs" << i + 1 << ": ";
        cin >> tmp;
        for (int j = 0; j < all.size(); j++)
            if (all[i].getID() == tmp)
            {
                idstudent.push_back(tmp);
                all[i].editSchedule(this->id);
                flag = 1;
                break;
            }
        if (!flag)
            cout << "STUDENT NOT FOUND\n", i--;
        else
            cout << "Assign Student To Classroom Done.\n";
    }
}
void Classroom::setTime()
{
    int a, b;
    cout << "Nhap gio bat dau: ";
    cin >> a;
    cout << "Nhap gio ket thuc: ";
    cin >> b;
    time.setTime(a, b);
    cout << "Set Time Done.\n";
}
void Manager::getWageOfTeacher()
{
    int id;
    cout << "id teacher: ";
    cin >> id;
    for (int i = 0; i < teacher.size(); i++)
        if (id == teacher[i].getID())
            cout << teacher[i].getSalary() << "$" << endl;
}

void Manager::addStudent()
{
    Student tmp;
    int n;
    cout << "Nhap so luong: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << Student::NUM_STUDENT << ":\n";
        tmp.addStudent();
        student.push_back(tmp);
    }
    cout << "Add Student Done.\n";
}
void Manager::addTeacher()
{
    Teacher tmp;
    int n;
    cout << "Nhap so luong: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << Teacher::NUM_TEACHER << ":\n";
        tmp.addTeacher();
        teacher.push_back(tmp);
    }
    cout << "Add Teacher Done.\n";
}
void Manager::showTeacherList()
{
    for (int i = 0; i < teacher.size(); i++)
    {
        cout << i + 1 << endl;
        teacher[i].showTeacher();
    }
}
void Manager::showStudentList()
{
    for (int i = 0; i < teacher.size(); i++)
    {
        cout << i + 1 << endl;
        student[i].showStudent();
    }
}

void Manager::editStudent()
{
    int target;
    cout << "Ma ID hoc sinh: ";
    cin >> target;
    for (int i = 0; i < student.size(); i++)
    {
        if (target == student[i].getID())
        {
            cout << "1. Change name";
            cout << "\n2. Change id";
            cout << "\n3. Change address";
            cout << "\n4. Change result";
            cout << "\n0. Exit";
            cout << "\nYour choice: ";
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                student[i].changeName();
                break;
            case 2:
                student[i].changeID();
                break;
            case 3:
                student[i].changeAddress();
                break;
            case 4:
                student[i].changeResult();
                break;
            }
            cout << "Thay doi thanh cong.\n";
            break;
        }
    }
}
void Manager::editTeacher()
{
    int target;
    cout << "Ma ID giao vien: ";
    cin >> target;
    for (int i = 0; i < teacher.size(); i++)
    {
        if (target == teacher[i].getID())
        {
            cout << "1. Change name";
            cout << "\n2. Change id";
            cout << "\n3. Change address";
            cout << "\n4. Change salary";
            cout << "\n0. Exit";
            cout << "\nYour choice: ";
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                teacher[i].changeName();
                break;
            case 2:
                teacher[i].changeID();
                break;
            case 3:
                teacher[i].changeAddress();
                break;
            case 4:
                teacher[i].changeSalary();
                break;
            }
            cout << "Thay doi thanh cong.\n";
            break;
        }
    }
}
void Manager::addClassroom()
{
    Classroom tmp;
    bool flag = 0;
    int idTeacher;
    cout << "Nhap id giao vien: ";
    cin >> idTeacher;
    tmp.setTeacher(idTeacher);
    for (int i = 0; i < teacher.size(); i++)
        if (idTeacher == teacher[i].getID())
        {
            teacher[i].editSchedule(tmp.getID());
            tmp.setStudent(student);
            tmp.setTime();
            cout << "Create Classroom Successfully\n";
            flag = 1;
            break;
        }
    if (!flag)
    {
        cout << "NOT FOUND TEACHER";
        return;
    }
    classroom.push_back(tmp);
}
void Manager::showScheduleOfTeacher()
{
    int idTeacher;
    bool flag = 0;
    cout << "Nhap id giao vien: ";
    cin >> idTeacher;
    for (int i = 0; i < teacher.size(); i++)
        if (idTeacher == teacher[i].getID())
        {
            vector<int> a = teacher[i].getSchedule();
            for (int j = 0; j < a.size(); j++)
            {
                cout << "id";
                cout << a[j];
                cout << ": ";
                classroom[a[j]].sayTime();
                cout << endl;
            }
            flag = 1;
            break;
        }
    if (!flag)
        cout << "NOT FOUND\n";
}
void Manager::showScheduleOfStudent()
{
    int idStudent;
    bool flag = 0;
    cout << "Nhap id Student: ";
    cin >> idStudent;
    for (int i = 0; i < student.size(); i++)
        if (idStudent == student[i].getID())
        {
            vector<int> a = student[i].getSchedule();
            cout << "size: " << a.size() << endl;
            for (int j = 0; j < a.size(); j++)
            {
                cout << "id";
                cout << a[j];
                cout << ": ";
                classroom[a[j]].sayTime();
                cout << endl;
            }
            flag = 1;
            break;
        }
    if (!flag)
        cout << "NOT FOUND\n";
}