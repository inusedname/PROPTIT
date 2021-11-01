#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int oo = 1e9 + 7;
using namespace std;
vector<int> a, stt;
int dem = 0;
int partition(int left, int right)
{
    int max = 0, index;
    for (int i = left; i <= right; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            index = i;
        }
    }
    stt[index] = dem;
    dem++;
    return index;
}
void find(int left, int right)
{
    if (left < right)
    {
        int pi = partition(left, right);
        find(left, pi - 1);
        dem--;
        find(pi + 1, right);
        dem--;
    }
    else
    {
        if (left == right)
            stt[left] = dem;
        dem++;
    }
}
void solve()
{
    dem = 0;
    int n;
    cin >> n;
    a.clear(), a.resize(n), stt.clear(), stt.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    find(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << stt[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}