#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
#define endl "\n"
#define vi vector<int>
#define vll vector<ll>
#define vii pair<int, int>
#define v2ll pair<ll, ll>
const int oo = 1e9;
const int MOD = 1e9 + 7;
using namespace std;
int nto(int n)
{
    if (n == 1)
        return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
void solve()
{
    int n, tmp, mmax = 0;
    cin >> n;
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        tmp = s[i] - '0';
        sum += tmp;
        if (tmp > mmax)
            mmax = tmp;
    }
    if (nto(sum))
    {
        cout << "NO";
        return;
    }
    for (int i = 2; i * i <= sum; i++)
    {
        if (sum % i == 0)
        {
            sum = sum / i;
            break;
        }
    }
    int subsum = 0;
    for (int i = 0; i < n; i++)
    {
        subsum += s[i] - '0';
        if (subsum > sum)
        {
            cout << "NO";
            return;
        }
        else if (subsum == sum)
            subsum = 0;
    }
    if (subsum < sum && subsum > 0)
        cout << "NO";
    else
        cout << "YES";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}