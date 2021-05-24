#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
struct u
{
    int val;
    int freq;
};
bool cmp(u x, u y)
{
    if (x.freq == y.freq)
        return x.val < y.val;
    return x.freq > y.freq;
}
void solve()
{
    int n, tmp;
    cin >> n;
    vector<u> ans;
    ans.resize(0);
    int a[100005] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a[tmp]++;
    }
    for (int i = 0; i < 100001; i++)
    {
        if (a[i])
        {
            u tmp2;
            tmp2.val = i;
            tmp2.freq = a[i];
            ans.push_back(tmp2);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++)
        for (int j = 0; j < ans[i].freq; j++)
            cout << ans[i].val << " ";
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