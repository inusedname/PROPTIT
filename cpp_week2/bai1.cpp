#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct student
{
    string name;
    bool gender;
    string id;
};

bool sapxep (student x1,student x2) // so sánh hai student dựa trên ID
{
    if (x1.id<x2.id)
        return true;
    return false;
}
int main()
{
    int t;
    cin >> t;
    vector<student> list(t);
    for (int i = 0; i < t;i++)
    {
        cin.ignore();
        getline(cin,list[i].name);
        cin >> list[i].gender;
        cin >> list[i].id;
    }
    sort(list.begin(), list.end(), sapxep); //sắp xếp
    for (int i = 0; i < t;i++)
    {
        cout << list[i].name << endl;
    }
}