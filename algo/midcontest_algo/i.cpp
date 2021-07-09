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

struct u
{
    int val;
    int stt;
    int rank;
};
bool cmp(u x, u y)
{
    return x.val < y.val;
}
bool cmp2(u x, u y)
{
    return x.stt < y.stt;
}
void solve()
{
    int n;
    cin >> n;
    vector<u> list(n);
    for (int i = 0; i < n; i++)
    {
        cin >> list[i].val;
        list[i].stt = i;
    }
    sort(list.begin(), list.end(), cmp);
    for (int i = 0; i < n; i++)
        list[i].rank = i;
    sort(list.begin(), list.end(), cmp2);
    for (int i = 0; i < n; i++)
        cout << list[i].rank << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
}