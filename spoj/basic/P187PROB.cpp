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
    int a[M]; //sàng era
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i < M; i++)
        a[i] = 1;
    for (int i = 2; i * i <= M; i++)
        if (a[i])
            for (int j = i * i; j < M; j += i)
                a[j] = 0;
    int b[M]; // tạo mảng tìm tổng
    b[0] = 0;
    b[1] = 0;
    for (int i = 2; i < M; i++)
    {
        if (a[i])
            b[i] = i;
        else
            for (int j = 2; j <= sqrt(i); j++)
            {
                if (i % j == 0)
                {
                    b[i] = j + b[i / j];
                    break;
                }
            }
    }
    for (int i = 0; i < n; i++)
        sum += b[ar[i]];
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