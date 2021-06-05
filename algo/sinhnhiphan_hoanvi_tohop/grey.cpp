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
    int n;
    cin >> n;
    vector<string> a;
    a.push_back("0");
    a.push_back("1");
    while (a.size() < pow(2, n))
    {
        for (int i = a.size() - 1; i >= 0; i--)
        {
            a.push_back("1" + a[i]);
            a[i] = "0" + a[i];
        }
    }
    for (int i = 0; i < pow(2, n); i++)
        cout << a[i] << " ";
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