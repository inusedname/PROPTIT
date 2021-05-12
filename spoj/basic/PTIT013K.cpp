#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
int gt[10] = {0};
ll n;
void solve()
{
    cin >> n;
    int sum = 0;
    int step = 1;
    int tmp;
    while (n > 0)
    {
        tmp = n % 10;
        sum += tmp * gt[step++];
        n /= 10;
    }
    cout << sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tich = 1;
    for (int i = 1; i < 10; i++)
    {
        tich *= i;
        gt[i] = tich;
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}