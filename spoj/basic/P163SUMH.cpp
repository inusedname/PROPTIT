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
    int a, b, k;
    cin >> a >> b;
    int ti = 0, bang = 0, teo = 0;
    for (int i = 1; i < 7; i++)
    {
        k = abs(i - a) - abs(i - b);
        if (k > 0)
            teo++;
        else if (k < 0)
            ti++;
        else
            bang++;
    }
    printf("%d %d %d", ti, bang, teo);
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