#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
int n, k;
int flag;
void Search(int begin, int end, vector<int> a)
{
    if (begin == end)
    {
        if (a[begin] == k && !flag)
        {
            cout << begin + 1;
            flag = 1;
        }
        return;
    }
    int mid = (begin + end) / 2;
    Search(begin, mid, a);
    Search(mid + 1, end, a);
}
void solve()
{
    flag = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Search(0, n - 1, a);
complete:
    if (!flag)
        cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}