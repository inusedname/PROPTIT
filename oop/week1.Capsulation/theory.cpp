#include <iostream>

using namespace std;

class Student
{
public:
    Student() { id++; };
    static void sayID()
    {
        cout << id << endl;
    }

private:
    static int id;
    string name;
    int age;

public:
    Student(string name, int age);
    void sayInfo()
    {
        cout << "name: " << name << endl
             << "age: " << age << endl;
    }
};

Student::Student(string name, int age)
{
    id++;
    this->name = name;
    this->age = age;
}

int Student::id = 0;
int main()
{
    Student st1("an", 19), st2("tuan", 20);
    st2.sayID();
    st1.sayInfo();
    st2.sayInfo();
}