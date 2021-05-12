#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
vector<int> check(10);
int ktra(ll n)
{
    while (n > 0)
    {
        int u = n % 10;
        check[u] = 1;
        n /= 10;
    }
}
void solve()
{
    ll n;
    int k;
    ll tmp;
    int flag;
    while (cin >> n;)
    {
        check.clear();
        check.resize(10, 0);
        k = 1;
        while (1)
        {
            flag = 1;
            tmp = k * n;
            ktra(tmp);
            for (int i = 0; i < 10; i++)
                if (check[i] == 0)
                {
                    k++;
                    flag = 0;
                    break;
                }
            if (flag == 1)
            {
                cout << k <;
                break;
            }
        }
    }
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
    }
}