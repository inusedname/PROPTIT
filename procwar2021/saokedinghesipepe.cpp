#include <bits/stdc++.h>
#define ll long long
const int oo = 1e9 + 7;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n + 5];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b[n + 5] = {0};
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] >= a[i + 1])
            b[i] = a[i + 1];
        else
        {
            int j = i + 1;
            while (i < n && a[i] < b[j])
                j++;
            if (i == n)
                b[i] = 0;
            else
                b[i] = b[j];
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] - b[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        printf("\n");
    }
}