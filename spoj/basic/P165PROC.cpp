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
        int n, m, t, du, dem, i;
        ll sum = 1;
        cin >> n >> m >> t;
        i = 1;
        dem = 0;
        while (i <= n)
        {
            dem++;
            i += t;
        }
        du = n - i + t + 1;
        sum *= dem * du;
        i = 1;
        dem = 0;
        while (i <= m)
        {
            dem++;
            i += t;
        }
        du = m - i + t + 1;
        sum *= dem * du;
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