#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";

void solve()
{
    int n;
    cin >> n;
    int a[n];
    int demchan = 0;
    int demle = 0;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp % 2)
            demle++;
        else
            demchan++;
    }
    int flag = 1;
    if (demle == 0)
        flag = 0;
    if (demle % 2 == 0 && demchan == 0)
        flag = 0;
    if (flag)
        cout << "YES";
    else
        cout << "NO";
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