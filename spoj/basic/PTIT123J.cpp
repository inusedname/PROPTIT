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
    while (1)
    {
        string s;
        getline(cin, s);
        if (s == ".")
            break;
        int flag = 1;
        for (int i = 0; i < s.size() - 1; i++)
        {
            while (s[i] == ')')
            {
                flag = 0;
                for (int j = i - 1; j >= 0; j--)
                    if (s[j] == '(')
                    {
                        s.erase(s.begin() + j, s.begin() + i + 1);
                        i = j;
                        flag = 1;
                        break;
                    }
                if (!flag)
                {
                    cout << "no\n";
                    break;
                }
            }
            while (s[i] == ']')
            {
                flag = 0;
                for (int j = i - 1; j >= 0; j--)
                    if (s[j] == '[')
                    {
                        s.erase(s.begin() + j, s.begin() + i + 1);
                        i = j;
                        flag = 1;
                        break;
                    }
                if (!flag)
                {
                    cout << "no\n";
                    break;
                }
            }
            if (flag)
                while (s[i] == ')')
                {
                    flag = 0;
                    for (int j = i - 1; j >= 0; j--)
                        if (s[j] == '(')
                        {
                            s.erase(s.begin() + j, s.begin() + i + 1);
                            i = j;
                            flag = 1;
                            break;
                        }
                    if (!flag)
                    {
                        cout << "no\n";
                        break;
                    }
                }
        }
        if (flag)
            cout << "yes\n";
        cin.ignore();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    solve();
}