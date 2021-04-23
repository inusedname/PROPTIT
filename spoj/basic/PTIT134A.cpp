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
        string s;
        while (cin >> s)
        {
            int dem = 0;
            int f[26] = {0};
            for (int i = 0; i < s.size(); i++)
            {
                f[s[i] - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                if (f[i] % 2)
                    dem++;
            }
            if (dem < 2 || dem % 2)
                cout << "First\n";
            else
                cout << "Second\n";
        }
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