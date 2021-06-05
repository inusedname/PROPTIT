    #include <iostream>
    #include <cmath>
    #include <vector>
    #include <string>
    #include <algorithm>
    using namespace std;
    typedef long long ll;
    typedef double db;
    #define endl "\n"
    int n, k, s;
    bool ktra(int a[])
    {
        int sum = 0;
        for (int i = 1; i <= k; i++)
        {
            sum += a[i];
            if (sum > s)
                return 0;
        }
        if (sum == s)
            return 1;
        return 0;
    }
    void solve()
    {
        while (1)
        {
            cin >> n >> k >> s;
            if (n == 0)
                break;
            if (n < k)
            {
                cout << 0 << endl;
                continue;
            }
            int a[k + 1];
            for (int i = 1; i <= k; i++)
                a[i] = i;
            int dem = 0;
            if (ktra(a))
                dem++;
            while (1)
            {
                int i = k;
                while (i > 0 && a[i] == n - k + i)
                    i--;
                if (i == 0)
                    break;
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[j - 1] + 1;
                if (ktra(a))
                    dem++;
            }
            cout << dem << endl;
        }
    }

    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        solve();
    }