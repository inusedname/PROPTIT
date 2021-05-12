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
    int mark = (n - 1) / 2;
    for (int i = 0; i < n; i++)
    {
        int tmp = i;
        if (i > mark)
            tmp = n - i - 1;
        else
            tmp = i;
        for (int j = 0; j < n; j++)
            if (tmp + j >= mark && j <= mark + tmp)
                cout << "D";
            else
                cout << "*";
        cout << endl;
    }
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