#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int oo = 1e9 + 7;
using namespace std;

int L[1005][1005];
int ans[1005] = {0};
string s1, s2;

void trace()
{
    int i = s1.size();
    int j = s2.size();
    while (i && j)
    {
        if (s1[i - 1] == s2[i - 1])
        {
            ans[i - 1] = 1;
            i--, j--;
        }
        else
        {
            if (L[i][j] == L[i - 1][j])
                i--;
            else
                j--;
        }
    }
    for (int i = 0; i < s1.size(); i++)
        if (ans[i])
            cout << s1[i];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s1 >> s2;
    for (int i = 1; i <= s1.size(); i++)
        for (int j = 1; j <= s2.size(); j++)
            if (s1[i - 1] == s2[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
    cout << L[s1.size()][s2.size()];
}