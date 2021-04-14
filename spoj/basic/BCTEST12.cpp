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
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            s[i] = tolower(s[i]);
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y')
            {
                s.erase(s.begin() + i);
                i--;
            }
            else
            {
                s.insert(s.begin() + i, '.');
                i++;
            }
        }
        cout << s;
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