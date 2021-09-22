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
    cout << MAX << endl;
    vector<int> ans;
    MAX++;
    for (int i = n; i >= 1; i--)
    {
        if (f[i] + 1 == MAX)
        {
            MAX--;
            ans.push_back(a[i]);
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
}