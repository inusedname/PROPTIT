    #include <iostream>
    #include <cmath>
    #include <vector>
    #include <string>
    #include <algorithm>
    using namespace std;
    typedef long long ll;
    typedef double db;
    #define endl "\n"

    void solve()
    {
        int n;
        cin >> n;
        cout << n << " ";
        string s;
        cin >> s;
        int i = s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1])
            i--;
        if (i < 0)
            cout << "BIGGEST";
        else
        {
            for (int j = s.size() - 1; j > i; j--)
                if (s[j] > s[i])
                {
                    swap(s[i], s[j]);
                    break;
                }
            for (int j = 0; j <= i; j++)
                cout << s[j];
            for (int j = s.size() - 1; j > i; j--)
                cout << s[j];
        }
    }

    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t;
        cin >> t;
        while (t--)
        {
            solve();
            cout << endl;
        }
    }