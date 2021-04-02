#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";

void solve()
{
    int n, k;
    cin >> n >> k;
    int dem = 0;
    int a[++n] = {0};
    for (int i = 2; i < n; i++)
    {
        if (!a[i])
        {
            if (++dem==k)
            {    
                cout << i;
                return;
            }
            for (int j = i * i; j < n; j += i)
            {
                if (!a[j])
                {
                    a[j] = 1;
                    if (++dem == k)
                    {
                        cout << j;
                        return;
                    }
                }
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
    solve();
}