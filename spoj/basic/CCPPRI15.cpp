#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int a[1000001];

void sto()
{
    int n = 1000000;
    n++;
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i < n; i++)
        a[i] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (a[i])
        {
            for (int j = i * i; j < n; j += i)
                a[j] = 0;
        }
    }
}

void solve()
{
    int t;
    cin >> t;
    int b[t];
    int max = 1;
    for (int i = 0; i < t; i++)
    {
        cin >> b[i];
        if (b[i] > max)
            max = b[i];
    }
    int c[max + 1];
    c[1] = 1;
    for (int i = 2; i <= max; i++)
    {
        if (a[i])
            c[i] = i;
        else
            for (int j = 2; j < i; j++)
                if (a[j])
                    if (i % j == 0)
                    {
                        c[i] = j;
                        break;
                    }
    }
    for (int i = 0; i < t; i++)
    {
        for (int j = 1; j <= b[i]; j++)
            cout << c[j] << " ";
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    sto();
    // while (t--)
    solve();
}