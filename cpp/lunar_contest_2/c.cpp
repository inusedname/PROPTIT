#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int v[n];
    for (auto &&i : v)
    {
        cin >> i;
    }
    sort(v, v + n);
    for (int i = n - 1; i > -1;i--)
    {
        cout << v[i] << " ";
    }
}