#include <bits/stdc++.h>
#define ll long long
#define arraycin(n)             \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define endl "\n"
const int oo = 1e9 + 7;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    char c;
    int f[128] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        f[tolower(c)]++;
    }
    int a[100];
    int j = 0;
    for (int i = 'a'; i <= 'z'; i++)
    {
        if (f[i] > 0)
        {
            a[j] = f[i];
            j++;
        }
    }
    for (int i = 0; i < j - 1; i++)
    {
        for (int t = i + 1; t < j; t++)
            if (a[i] < a[t])
            {
                int tmp = a[i];
                a[i] = a[t];
                a[t] = tmp;
            }
    }
    if (j < 3 || a[0] <= a[1] + a[2])
        cout << "So beautiful";
    else
        cout << "So ugly";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}