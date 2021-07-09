#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
vector<string> a;
int n;
int mmin = 999;
int f[11] = {0};
int ans[11];
int duplicate(string a, string b)
{
    int dem = 0;
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j])
                dem++;
            if (a[i] <= b[j])
                break;
        }
    return dem;
}
void Try(int j)
{
    for (int i = 0; i < n; i++)
        if (f[i] == 0)
        {
            f[i] = 1;
            ans[j] = i;
            if (j == n - 1)
            {
                // for (int j = 0; j < n; j++)
                //     cout << ans[j];
                // cout << endl;
                int sum = 0;
                for (int j = 0; j < n - 1; j++)
                {
                    sum += duplicate(a[ans[j]], a[ans[j + 1]]);
                    if (sum >= mmin)
                        break;
                }
                if (sum < mmin)
                    mmin = sum;
            }
            else
                Try(j + 1);
            f[i] = 0;
        }
}
void solve()
{
    cin >> n;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Try(0);
    cout << mmin;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
}