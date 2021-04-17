#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int n, k;
int b[22];
void xuatnghiem()
{
    for (int i = 1; i <= k; i++)
        cout << b[i];
    cout << " ";
}
void dequi(int i)
{
    for (int j = b[i - 1] + 1; j <= n - k + i; j++)
    {
        b[i] = j;
        if (i == k)
            xuatnghiem();
        else
            dequi(i + 1);
    }
}
void solve()
{
    cin >> n >> k;
    b[0] = 0;
    dequi(1);
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}