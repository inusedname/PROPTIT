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
    int demto = 0;
    while (n--)
    {
        int dem = 0;
        int tmp;
        for (int i = 0; i < 3; i++)
        {
            cin >> tmp;
            if (tmp)
                dem++;
        }
        if (dem > 1)
            demto++;
    }
    cout << demto;
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