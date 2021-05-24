#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"

int lower(int a[], int l, int r, int x)
{ //lớn hơn bằng x
    int val = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] >= x)
        {
            r = mid - 1;
            val = mid;
        }
        else
            l = mid + 1;
    }
    return val;
}
int upper(int a[], int l, int r, int x)
{ //lớn hơn x
    int res = -1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] > x)
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}
void solve()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Lower: " << lower(a, 0, n - 1, x);
    cout << "\nUpper: " << upper(a, 0, n - 1, x);
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