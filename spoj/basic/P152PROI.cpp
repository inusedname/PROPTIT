#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
void xuat(ll mau, ll tu)
{
    if (tu != 1)
        cout << tu;
    cout << "$";
    if (mau > 1)
        cout << "/" << mau;
    cout << endl;
}
void solve()
{
    ll n;
    cin >> n;
    ll mau = 180;
    ll tu = n;
    if (tu % 180 == 0)
    {
        tu /= mau;
        mau = 0;
        xuat(mau, tu % 2);
        return;
    }
    if (180 % tu == 0)
    {
        mau /= tu;
        tu = 1;
        xuat(mau, tu);
        return;
    }
    int flag = 0;
    if (tu > mau)
    {
        ll k = tu;
        tu = mau;
        mau = k;
        flag = 1;
    }
    ll fixed = tu;
    for (int i = 2; i * i <= fixed; i++)
    {
        while (tu % i == 0 && mau % i == 0)
        {
            tu /= i;
            mau /= i;
        }
    }
    if (flag)
    {
        ll k = tu;
        tu = mau;
        mau = k;
    }
    while ((float)tu / mau > 2.00)
    {
        tu -= 2 * mau;
    }
    xuat(mau, tu);
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