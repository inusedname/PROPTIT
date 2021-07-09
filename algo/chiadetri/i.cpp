    #include <iostream>
    #include <cmath>
    #include <vector>
    #include <string>
    #include <algorithm>
    using namespace std;
    typedef long long ll;
    typedef double db;
    #define endl "\n"
    const ll MOD = 1e9 + 7;
    int MAX = 200001;
    ll luythua(ll x, int k)
    {
        if (k == 1)
            return x;
        if (k % 2 == 0)
            return (luythua(x, k / 2) * luythua(x, k / 2)) % MOD;
        return ((luythua(x, k / 2) * luythua(x, k / 2)) % MOD * x) % MOD;
    }
    vector<int> freq;
    void solve()
    {
        freq.assign(MAX, 0);
        int n;
        cin >> n;
        ll x = 1;
        int tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            x = (x * tmp) % MOD;
            freq[tmp]++;
        }
        int souoc = 0;
        for (int i = 2; i < MAX; i++)
        {
            if (freq[i])
                souoc += freq[i] + 1;
        }
        ll ans = luythua(x, souoc / 2);
        if (souoc % 2)
            ans = (ans * ll(sqrt(x))) % MOD;
        cout << ans;
    }

    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        // int t;
        // cin >> t;
        // while (t--)
        {
            solve();
            cout << endl;
        }
    }