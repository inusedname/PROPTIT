// Thuật toán tham lam:
// https://vn.spoj.com/problems/CAR

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct car
{
    double fine;
    double days;
    int stt;
};

bool sapxep(car x1, car x2)
{
    // if (x1.fine/x1.days == x2.fine/x2.days)
    //     return x1.fine < x2.fine;
    return x1.fine / x1.days > x2.fine / x2.days;
}
int main()
{
    int n;
    cin >> n;
    vector<car> list(n);
    for (int i = 0; i < n; i++)
    {
        cin >> list[i].fine;
        list[i].stt = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> list[i].days;
    }
    sort(list.begin(), list.end(), sapxep);
    unsigned long long sum = 0;
    long long daypass = 0;
    for (int i = 0; i < n; i++)
    {
        sum += list[i].fine * (list[i].days + daypass);
        daypass += list[i].days;
    }
    cout << sum << endl;
    for (int i = 0; i < n; i++)
    {
        cout << list[i].stt << " ";
    }
}