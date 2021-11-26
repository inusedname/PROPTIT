#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Student
{
private:
    string ID;
    string name;
    string birth;
    string gender;
    string classroom;

public:
    Student(){};  // CONSTRUCTOR
    ~Student(){}; // DESTRUCTOR
    void setID();
    void setName();
    void setBirth();
    void setGender();
    void setClass();
    void setInfo();
    void getInfo();
    string getID();
    string getName();
    friend bool operator<(Student, Student); // NẠP CHỒNG TOÁN TỬ SO SÁNH TÊN (TĂNG DẦN THEO BẢNG CHỮ CÁI)
};

class School
{
private:
    vector<Student> students;

public:
    School(){};
    ~School(){};
    void heapSort();                // SO SÁNH HEAPSORT
    int binarySearchbyName(string); // TÌM KIẾM NHỊ PHÂN THEO TÊN
    void addStudent();
    void rmStudent();
    void modStudent();
    void sortbyName();
    void showAll();
    void searchByName();
};