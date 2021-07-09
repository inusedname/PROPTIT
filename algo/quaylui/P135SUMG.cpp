#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
string s;
char vowel[] = "AEIOU";
vector<int> posi;
bool check(char c)
{
    for (int i = 0; i < 5; i++)
        if (c == vowel[i])
            return 1;
    return 0;
}
void Try(int i)
{
    for (char j = '0'; j <= '1'; j++)
    {
        if (posi[i] - 2 >= 0)
            if (posi[i - 2] == j && posi[i - 1] == j)
                
    }
}
void solve()
{
    cin >> s;
    int res = 0;
    bool L = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'L')
            L = 1;
        if (check(s[i]))
            s[i] = '1';
        else if (isalpha(s[i]))
            s[i] = '0';
        else
            posi.push_back(i);
    }
    if (L)
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