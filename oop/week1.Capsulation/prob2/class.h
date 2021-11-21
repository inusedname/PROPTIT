#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Address
{
private:
    string hometown;
    string currentAdd;

public:
    string getHometown();
    string getCurrentAdd();
    void setHometown(string hometown);
    void setCurrentAdd(string currentadd);
};

class Room
{
public:
    static int NUM_ROOM;

private:
    int id;
    int cap;

public:
    Room() { NUM_ROOM++; };
};

class Time
{
    int start;
    int end;

public:
    pair<int, int> showTime();
    void setTime(int start, int end);
};

class Transcript
{
    double history, english, math;

public:
    void setTranscript(double history, double english, double math);
    void getTranscript();
};
class Student
{
public:
    static int NUM_STUDENT;

private:
    int id;
    string name;
    Address address;
    Transcript result;
    vector<int> classID;

public:
    Student() { NUM_STUDENT++; }
    void addStudent();
    void editStudent();
    void showStudent();
    void changeID();
    void changeName();
    void changeAddress();
    void changeResult();
    void editSchedule(int id);
    int getID();
    vector<int> getSchedule();
};

class Teacher
{
public:
    static int NUM_TEACHER;

private:
    int id;
    string name;
    Address address;
    int salary;
    vector<int> classID;

public:
    Teacher() { NUM_TEACHER++; }
    void addTeacher();
    void editTeacher();
    void showTeacher();
    void editSchedule(int id);
    void changeID();
    void changeName();
    void changeAddress();
    void changeSalary();
    int getSalary();
    int getID();
    vector<int> getSchedule();
};
class Classroom
{
    static int NUM_CLASSROOM;
    Teacher idteacher;
    vector<int> idstudent;
    Time time;
    int id;

public:
    Classroom()
    {
        id = NUM_CLASSROOM;
        NUM_CLASSROOM++;
    }
    void getTeacher();
    int getID();
    void sayTime();
    void setTeacher(int idTeacher);
    void setStudent(vector<Student> &student);
    void setTime();
};
class Manager
{
    vector<Teacher> teacher;
    vector<Room> room;
    vector<Student> student;
    vector<Classroom> classroom;

public:
    vector<Student> getStudent();
    void addStudent(); //done
    void addTeacher(); //done
    // void addRoom();
    void addClassroom(); //done
    void editTeacher();                          //modify done - delete not done
    void editStudent();                          //modify done - delete not done
    void showTeacherList();                      //done
    void showStudentList();                      //done
    void showScheduleOfTeacher();                //done
    void showScheduleOfStudent();                //done
    void getWageOfTeacher();                     //done
};
