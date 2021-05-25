#include <iostream>
#include <cmath>
using namespace std;
#define endl "\n";

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int first[t], last[t];
    int max = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> first[i] >> last[i];
        if (last[i] > max)
            max = last[i];
    }
    int a[max + 1] = {0};
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= max; i++)
    {
        if (a[i] == 0)
        {
            for (int j = i * 2; j <= max; j += i)
                a[j]++;
        }
    }
    for (int i = 2; i <= max; i++)
    {
        if (a[i] == 0)
            a[i] = 1;
    }
    long long l[max + 1];
    l[0] = 0;
    l[1] = 0;
    for (int i = 2; i <= max; i++)
    {
        l[i] = l[i - 1] + a[i];
    }
    for (int i = 0; i < t; i++)
    {
        cout << l[last[i]] - l[first[i] - 1] << endl;
    }
}