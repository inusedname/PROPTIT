#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int stack[10000];

void solve()
{
    string s; //CH(CO2H)3
    cin >> s;
    int dem = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'C')
            stack[dem] = 12;
        else if (s[i] == 'H')
            stack[dem] = 1;
        else if (s[i] == 'O')
            stack[dem] = 16;
        else if (s[i] == '(')
            stack[dem] = 0;
        else if (s[i] == ')')
        {
            int sum = 0;
            while (stack[--dem] > 0)
            {
                sum += stack[dem];
            }
            stack[dem] = sum;
        }
        else
            stack[dem-- - 1] *= (s[i] - '0');
        dem++;
    }
    dem--;
    int k = 0;
    while (dem >= 0)
        k += stack[dem--];
    cout << k;
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