#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
char a[4][4];
int convert(char a)
{
    if (a == '#')
        return 1;
    else
        return 0;
}
int ktra(int i, int j)
{
    int cham = 0;
    int thang = 0;
    if (convert(a[i][j]))
        thang++;
    else
        cham++;
    if (convert(a[i][j - 1]))
        thang++;
    else
        cham++;
    if (convert(a[i + 1][j]))
        thang++;
    else
        cham++;
    if (convert(a[i + 1][j - 1]))
        thang++;
    else
        cham++;
    if (cham > 2 || thang > 2)
        return 1;
    else
        return 0;
}
void solve()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> a[i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 1; j < 4; j++)
        {
            if (ktra(i, j))
            {
                cout << "YES";
                return;
            }
        }
    cout << "NO";
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