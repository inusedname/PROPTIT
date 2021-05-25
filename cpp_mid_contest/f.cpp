#include <iostream>
#include <string>
using namespace std;

int main()
{
    char a[1000];
    cin >> a;
    int b;
    cin >> b;
    int i = 0;
    int tong = 0;
    while (a[i] != '\0')
    {
        int tmp = (int)a[i] - 48;
        tong = tong * 10 + tmp;
        tong %= b;
        i++;
    }
    cout << tong;
}