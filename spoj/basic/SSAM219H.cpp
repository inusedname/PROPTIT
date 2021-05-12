#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
bool cmp(int x, int y)
{
    return x > y;
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    int f[10] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 3)
            f[a[i]]++;
        sum += a[i];
    }
    int tmp;
    sort(a, a + n, cmp);
    // for (int i = 1; i < 10; i++)
    //     cout << f[i];
    // cout << endl;
    if (sum % 3 == 0)
        for (int i = 0; i < n; i++)
            cout << a[i];
    else
    {
        for (int i = 8; i > 1; i--)
            if (f[i])
            {
                if (f[i] % 3 == 0)
                {
                    f[i] = 0;
                    continue;
                }
                int j;
                if (i % 3 == 1)
                    j = i - 2;
                else
                    j = i - 1;
                for (; j > 0; j -= 3)
                    if (f[j])
                        if (f[i] > f[j])
                        {
                            f[i] -= f[j];
                            f[j] = 0;
                        }
                        else
                        {
                            f[j] -= f[i];
                            f[i] = 0;
                            break;
                        }
            }

        int dem = 0;
        int flag = 0;
        // for (int i = 1; i < 10; i++)
        //     cout << f[i];
        // cout << endl;
        for (int i = 0; i < n; i++)
        {
            if (f[a[i]])
            {
                f[a[i]]--;
                continue;
            }
            flag = 1;
            cout << a[i];
        }
        if (flag == 0)
            cout << -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}