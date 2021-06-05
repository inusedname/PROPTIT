#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
void IN(int a[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << " ";
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void solve()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        a[i] = n - i + 1;
    IN(a, n);
    while (1)
    {
        int i = n - 1;
        while (i >= 1 && a[i] < a[i + 1])
            i--;
        if (i < 1)
            break;
        for (int j = n; j > i; j--)
            if (a[j] < a[i])
            {
                swap(&a[j], &a[i]);
                break;
            }
        int l = i + 1;
        int r = n;
        while (l < r)
        {
            swap(&a[l], &a[r]);
            l++, r--;
        }
        IN(a, n);
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