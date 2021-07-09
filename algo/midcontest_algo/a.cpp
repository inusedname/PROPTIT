#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
#define endl "\n"
#define pi pair<int, int>
#define pll pair<ll, ll>
const int oo = 1e9;
const int MOD = 1e9 + 7;

using namespace std;
vector<int> a;
int n;
void solve()
{
    int x, k;
    cin >> x >> k;
    int start = lower_bound(a.begin(), a.end(), x) - a.begin();
    int finish = upper_bound(a.begin(), a.end(), x) - a.begin();
    finish--;
    if (start == n)
        start--;
    while (finish - start < k - 1)
    {
        if (start > 0 && finish < n - 1)
            if (x - a[start - 1] < a[finish + 1] - x)
                start--;
            else
                finish++;
        else if (start == 0)
            finish++;
        else
            start--;
    }
    if (finish > start + k - 1)
        finish = start + k - 1;
    for (int i = start; i <= finish; i++)
        cout << a[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> n;
    cin >> t;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    while (t--)
    {
        solve();
        cout << endl;
    }
}