    #include <iostream>
    #include <cmath>
    #include <vector>
    #include <string>
    #include <algorithm>
    using namespace std;
    typedef long long ll;
    typedef double db;
    #define endl "\n";

    int nto(ll n)
    {
        if (n == 1)
            return 0;
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return 0;
        return 1;
    }
    void solve()
    {
        ll n;
        cin >> n;
        ll multi = 1;
        if (nto(n))
        {
            multi *= n;
            cout << multi;
            return;
        }
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0 && nto(i))
                multi *= i;
            if (n % i == 0 && nto(n / i))
                multi *= (n / i);
        }
        if ((float)sqrt(multi) == sqrt(multi))
            multi /= sqrt(multi);
        cout << multi;
        // for (ll i = 1; i <= sqrt(n); i++)
        // {
        //     if (n % i == 0)
        //     {
        //         ll b = n / i;
        //         int dem = 0;
        //         for (ll j = 2; j <= b; j++)
        //         {
        //             if (b % j == 0)
        //             {
        //                 dem++;
        //                 b /= j;
        //                 if (dem > 1)
        //                     break;
        //             }
        //             else
        //                 dem = 0;
        //         }
        //         if (b == 1)
        //         {
        //             cout << n / i;
        //             return;
        //         }
        //     }
        // }
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