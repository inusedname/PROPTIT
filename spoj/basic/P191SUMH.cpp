#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
int case1(int markup[][50], int i, int j)
{
    if (markup[i + 1][j - 1] == 1)
        return 0;
    if (markup[i + 1][j] == 1)
        return 0;
    if (markup[i + 1][j + 1] == 1)
        return 0;
    if (markup[i + 2][j] == 1)
        return 0;
    return 1;
}
int case2(int markup[][50], int i, int j)
{
    if (markup[i - 1][j + 1] == 1)
        return 0;
    if (markup[i][j + 1] == 1)
        return 0;
    if (markup[i][j + 2] == 1)
        return 0;
    if (markup[i + 1][j + 1] == 1)
        return 0;
    return 1;
}
int case3(int markup[][50], int i, int j)
{
    if (markup[i - 1][j] == 1)
        return 0;
    if (markup[i][j - 1] == 1)
        return 0;
    if (markup[i][j + 1] == 1)
        return 0;
    if (markup[i + 1][j] == 1)
        return 0;
    return 1;
}
int case4(int markup[][50], int i, int j)
{
    if (markup[i - 1][j - 1] == 1)
        return 0;
    if (markup[i - 1][j] == 1)
        return 0;
    if (markup[i - 1][j] == 1)
        return 0;
    if (markup[i + 1][j - 1] == 1)
        return 0;
    return 1;
}
int case5(int markup[][50], int i, int j)
{
    if (markup[i - 2][j] == 1)
        return 0;
    if (markup[i - 1][j - 1] == 1)
        return 0;
    if (markup[i - 1][j] == 1)
        return 0;
    if (markup[i - 1][j + 1] == 1)
        return 0;
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    char tmp;
    int a[n][n];
    for (int i = 0; i < n * n; i++)
    {
        cin >> tmp;
        if (tmp == '#')
            a[i / n][i % n] = 1;
        else
            a[i / n][i % n] = 0;
    }
    int markup[n][n] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 0)
            {
                if ()
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