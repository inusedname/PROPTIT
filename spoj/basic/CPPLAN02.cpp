#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
// #define endl "\n";
string a, b;
int nho = 0, sum;
vector<int> ans;
void solve()
{
    nho = 0;
    ans.clear();
    a.clear();
    b.clear();
    cin >> a;
    cin.ignore();
    cin >> b;
    while (a.size() > b.size())
        b = "0" + b;
    while (a.size() < b.size())
        a = "0" + a;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        sum = a[i] + b[i] + nho - '0' - '0';
        nho = sum / 10;
        sum %= 10;
        ans.push_back(sum);
    }
    if (nho)
        ans.push_back(nho);
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
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