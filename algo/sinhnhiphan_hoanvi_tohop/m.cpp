#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
struct dat
{
    int NT;
    int NS;
};
vector<dat> ch;
vector<int> a;
int n, sum = 0;
int kq = 1e9;
dat tinh(string s)
{
    int res1 = 0, res2 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            res1 += a[i];
            res2 += a[i + n / 2];
        }
    }
    return {res1, res2};
}
void sinhnp(int vt, string s)
{
    if (vt > n / 2)
    {
        ch.push_back(tinh(s));
        return;
    }
    sinhnp(vt + 1, s + '0');
    sinhnp(vt + 1, s + '1');
}
bool cmp(dat x, dat y)
{
    return x.NS < y.NS;
}
void BS(int l, int r, dat x)
{
    if (l > r)
        return;
    int mid = (l + r) / 2;
    int A = x.NT + ch[mid].NS; // ch[0].NT + ch[mid].NS
    int B = sum - A;
    kq = min(abs(A - B), kq);
    if (A == B)
        return;
    if (A > B)
        BS(l, mid - 1, x);
    else
        BS(mid + 1, r, x);
}
void solve()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sinhnp(1, "");
    sort(ch.begin(), ch.end(), cmp);
    for (int i = 0; i < ch.size(); i++)
    {
        dat tmp = ch[i];
        BS(0, ch.size() - 1, tmp);
    }
    cout << kq;
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