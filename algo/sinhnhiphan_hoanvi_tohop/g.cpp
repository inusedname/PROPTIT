#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
int n;
void IN(vector<int> b)
{
    cout << "(";
    int daucach = b.size() - 1;
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i];
        if (daucach)
        {
            cout << " ";
            daucach--;
        }
    }
    cout << ") ";
}
vector<int> a;
void solve()
{
    cin >> n;
    int res = n;
    while (res >= 1)
    {
        a.clear();
        int sum = res;
        a.push_back(res);
        for (int i = res; i >= 1; i--)
        {
            if (a.back() + i <= n)
            {
                a.push_back(i);
                sum += i;
            }
            if (sum == n)
            {
                IN(a);
                a.clear();
                a.push_back(res);
            }
        }
        res--;
    }
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