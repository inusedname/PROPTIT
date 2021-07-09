#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
int n;
ll i;
ll fi[93];
char Try(int n, ll i)
{
    if (n == 1)
        return 'A';
    else if (n == 2)
        return 'B';
    if (i <= fi[n - 2])
        return Try(n - 2, i);
    else
        return Try(n - 1, i - fi[n - 2]);
}
void solve()
{
    cin >> n >> i;
    cout << Try(n, i);
}

int main()
{
    fi[1] = 1;
    fi[2] = 1;
    for (int i = 3; i < 93; i++)
        fi[i] = fi[i - 2] + fi[i - 1];
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}