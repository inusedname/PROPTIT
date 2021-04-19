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
        cin.ignore();
        string s;
        cin >> s;
        if (s[0] > '4' && s[0] < '9')
            s[0] = '9' - s[0] + '0';
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] > '4')
                s[i] = '9' - s[i] + '0';
        }
        while (s[0] == '0' && s.size() > 1)
        {
            s.erase(s.begin());
        }
        cout << s << endl;
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