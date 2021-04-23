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
    string s;
    int n;
    cin >> n;
    cin.ignore();
    cin >> s;
    int sum = 0;
    int k;
    for (int i = 0; i < n / 2; i++)
    {
        k = s[i] - '0';
        if (k != 4 && k != 7)
        {
            cout << "NO";
            return;
        }
        sum += k;
    }
    for (int i = n / 2; i < n; i++)
    {
        {
            k = s[i] - '0';
            if (k != 4 && k != 7)
            {
                cout << "NO";
                return;
            }
            sum -= k;
        }
    }
    if (sum == 0)
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
}