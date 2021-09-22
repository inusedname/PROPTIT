#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"
int const M = 1e9;
using namespace std;

vector<int> a;
vector<int> f;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    a.resize(n + 5), f.resize(n + 5, 1);
    a[0] = 0, a[n + 1] = M;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int MAX = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
        }
        MAX = max(MAX, f[i]);
    }
    f[0] = 0;
    cout << MAX << endl;
    vector<int> ans(MAX + 1, 0);
    int val = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!ans[f[i]])
        {
            ans[f[i]] = i;
        }
        else if (a[i] > a[ans[f[i] - 1]])
        {
            if (!a[ans[f[i] + 1]] || a[i] < a[ans[f[i] + 1]])
                if (a[i] < a[ans[f[i]]])
                    ans[f[i]] = i;
        }
    }
    for (int i = 1; i <= MAX; i++)
        cout << a[ans[i]] << " ";
}