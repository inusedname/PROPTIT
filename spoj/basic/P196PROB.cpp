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
    int min = 999999;
    int max = 0;
    int tmp;
    for (int i = 0; i < 3;i++)
    {
        cin >> tmp;
        if (tmp>max)
            max = tmp;
        if (tmp<min)
            min = tmp;
    }
    cout << max - min;
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