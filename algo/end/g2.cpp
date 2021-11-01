#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int oo = 1e9 + 7;
using namespace std;

string s;
void printOdd(int n)
{
    for (int i = 0; i * 2 < n; i++)
        cout << 4;
    for (int i = 0; i * 2 < n; i++)
        cout << 7;
}
void solve()
{
    cin >> s;
    int n = s.size();
    string ori = s;
    if (n % 2)
    {
        printOdd(n);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] > '7')
        {
            int flag = 0;
            for (int j = 0; j < i; j++)
            {
                if (ori[j] != '7')
                    flag = 1;
            }
            if (!flag || i == 0)
            {
                printOdd(n + 2);
                return;
            }
            else
            {
                s[i] = '4';
                int flag = 0;
                for (int j = 0; j < i; j++)
                {
                    if (ori[j] < s[j])
                        flag = 1;
                }
                if (!flag)
                {
                    for (int j = i - 1; j >= 0; j--)
                        if (s[j] == '4')
                        {
                            s[j] = '7';
                            for (int k = j + 1; k < i; k++)
                                if (s[k] == '7')
                                {
                                    s[k] = '4';
                                    break;
                                }
                            break;
                        }
                }
            }
        }
        else if (s[i] > '4')
        {
            int flag = 0;
            for (int j = 0; j < i; j++)
            {
                if (ori[j] < s[j])
                    flag = 1;
            }
            if (!flag)
                s[i] = '7';
            else
                s[i] = '4';
        }
        else if (s[i] < '4')
            s[i] = '4';
    }
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '4')
            dem++;
    if (dem * 2 > n)
    {
        for (int i = n - 1; dem * 2 > n && i >= 0; i--)
            if (s[i] == '4')
            {
                s[i] = '7';
                dem--;
            }
    }
    else if (dem * 2 < n)
    {
        for (int i = n - 1; i >= 0; i--)
            if (s[i] == '4')
            {
                s[i] = '7';
                dem--;
                for (int j = i + 1; dem * 2 < n && j < n; j++)
                    s[j] = '4', dem++;
                break;
            }
    }
    if (dem * 2 != n)
        printOdd(n + 2);
    else
        cout << s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}