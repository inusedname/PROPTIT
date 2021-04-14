#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
ll M = -99999;
void solve()
{
    int n;
    cin >> n;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        if (ar[i] > M)
            M = ar[i];
    }
    M++;
    ll sum = 0;
    int a[M];
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i < M; i++)
        a[i] = 1;
    for (int i = 2; i * i <= M; i++)
        if (a[i])
            for (int j = i * i; j < M; j += i)
                a[j] = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[ar[i]])
        {
            sum += ar[i];
            continue;
        }
        else
            for (int j = 2; j * j <= ar[i]; j++)
                if (a[j])
                    while (ar[i] % j == 0)
                    {
                        ar[i] /= j;
                        sum += j;
                        if (a[ar[i]])
                        {
                            sum += ar[i];
                            ar[i] = 1;
                        }
                    }
    }
    cout << sum;
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