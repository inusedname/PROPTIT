#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int a[22] = {0};
int n;
int b[22];
int dem = 0;
void xuat(int b[])
{
    for (int i = 0; i < n; i++)
        cout << b[i];
    cout << " ";
}
void dequi()
{
    for (int i = 1; i <= n; i++)
    {
        if (!a[i])
        {
            a[i] = 1;
            b[dem++] = i;
            if (dem == n)
                xuat(b);
            else
                dequi();
            a[i] = 0;
            dem--;
        }
    }
}
void solve()
{
    cin >> n;
    dequi();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}