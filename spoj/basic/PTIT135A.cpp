#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int a, b, c, tmp1, tmp2, dem = 0;
int tinhtong(int dem)
{
    if (dem == 1)
        return a;
    else if (dem == 2)
        return b * 2;
    else if (dem == 3)
        return c * 3;
}
void solve()
{
    cin >> a >> b >> c;
    int m[3], n[3];
    int p[6];
    for (int i = 0; i < 3; i++)
    {
        cin >> tmp1 >> tmp2;
        m[i] = tmp1;
        n[i] = tmp2;
        p[dem++] = tmp1;
        p[dem++] = tmp2;
    }
    sort(p, p + 6);
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        dem = 0;
        for (int j = 0; j < 3; j++)
            if (m[j] <= p[i] && p[i + 1] <= n[j])
                dem++;
        sum += tinhtong(dem) * (p[i + 1] - p[i]);
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
    {
        solve();
        cout << endl;
    }
}