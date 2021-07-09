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
int a[100];
void IN(int n)
{
    cout << "[";
    for (int i = 0; i < n - 1; i++)
        cout << a[i] << " ";
    cout << a[n - 1] << "]\n";
}
void quaylui(int n)
{
    if (n == 0)
        return;
    for (int j = 0; j < n; j++)
        a[j] += a[j + 1];
    IN(n);
    quaylui(n - 1);
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    IN(n);
    quaylui(n - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}