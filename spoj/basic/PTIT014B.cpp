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
    ll ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    ll r = by - ay + dy - cy;
    ll d = bx - ax + dx - cx;
    int flag = 1;
    if (abs(by - dy) + abs(ay - cy) > r)
        flag = 0;
    if (abs(bx - dx) + abs(ax - cx) > d)
        flag = 0;
    if (flag)
        cout << "1\n";
    else
        cout << "0\n";
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