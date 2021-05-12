#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"

void solve()
{
    int a[1001] = {0};
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a[tmp]++;
    }
    int max = 0;
    for (int i = 1; i <= 1000; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    for (int i = 1; i <= 1000; i++)
    {
        if (a[i] == max)
        {
            cout << i;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}