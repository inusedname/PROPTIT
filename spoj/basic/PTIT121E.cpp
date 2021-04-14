#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";

int mass(char a)
{
    if (a == 'C')
        return 12;
    if (a == 'H')
        return 1;
    if (a == 'O')
        return 16;
}
int sumMass(string a)
{
    int subSum = 0;
    for (int i = 0; i < a.size(); i++)
        subSum += mass(a[i]);
    return subSum;
}
void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) // Loại bỏ dấu ngoạc dư thừa
    {
        if (s[i] == ')' && !isdigit(s[i + 1]))
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (s[j] == '(')
                {
                    s.erase(s.begin() + i);
                    s.erase(s.begin() + j);
                    i = i - 2;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < s.size(); i++) //Phá ngoặc
    {
        if (s[i] == ')')
        {
            string s2;
            int num = s[i + 1] - '0';
            num--;
            for (int j = i - 1; j >= 0; j--)
            {
                if (s[j] == '(')
                {
                    s2 = s.substr(j + 1, i - j - 1);
                    s.erase(s.begin() + i + 1);
                    s.erase(s.begin() + i);
                    s.erase(s.begin() + j);
                    i = i - 1;
                    while (num > 0)
                    {
                        s.insert(i, s2);
                        num--;
                    }
                    break;
                }
            }
        }
    }
    for (int i = 0; i < s.size(); i++) //Duyệt các phân tử đa không có ngoặc
    {
        if (isdigit(s[i]))
        {
            string s2 = s.substr(i - 1, 1);
            int a = s[i] - '0';
            s.erase(s.begin() + i);
            while (a > 1)
            {
                s.insert(i - 1, s2);
                a--;
            }
        }
    }
    cout << sumMass(s);
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