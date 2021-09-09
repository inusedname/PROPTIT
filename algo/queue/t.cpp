#include <iostream>
#include <deque>
#define ll long long
#define endl "\n"
using namespace std;
deque<int> dq;

void print()
{
    deque<int> tmp = dq;
    while (!tmp.empty())
    {
        cout << tmp.back() << " ";
        tmp.pop_back();
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    dq.push_back(1);
    dq.push_back(54);
    dq.push_back(23);
    dq.push_back(9);
    // khởi tạo
    print();
    // bỏ 1 phần tử ở cuối mảng
    dq.pop_back();
    print();
    dq.pop_front();
    print();
}