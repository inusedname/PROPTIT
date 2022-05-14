// File header: khai báo các properties và method của class đó
// File c++: định nghĩa các method

#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Worker
{
    // Properties - thuộc tính
public:
    string name;
    int age;
    bool gender; // gender boolean
    string hometown;
    int dayWorked;
    int rank;

    // Methods - phương thức
public:
    // Constructor là hàm sẽ được chạy ngay khi khởi tạo biến
    Worker(){};
    void addNew();
    void getInfo();
    int getDay();
    int getSalary();
};