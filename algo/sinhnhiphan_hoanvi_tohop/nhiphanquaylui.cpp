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
void dequi(string s)
{
    if (s.size() == n)
        cout << s << " ";
    else
    {
        dequi(s + "0");
        dequi(s + "1");
    }
}
void solve()
{
    cin >> n;
    dequi("");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
}