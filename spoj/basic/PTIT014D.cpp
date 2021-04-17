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
    string a;
    cin >> a;
    cin.ignore();
    int num = 0;
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
        num += a[i] - '0';
    while (1)
    {
        sum += num % 10;
        num /= 10;
        if (num == 0)
            if (sum > 17)
            {
                num = sum;
                sum = 0;
            }
            else if (sum == 9)
            {
                cout << "1\n";
                break;
            }
            else
            {
                cout << "0\n";
                break;
            }
    }
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