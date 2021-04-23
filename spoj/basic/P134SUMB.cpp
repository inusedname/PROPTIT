#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
int main()
{
    int g;
    ll y;
    cin >> g >> y;
    if (g == 2)
    {
        cout << 1 << " " << g + y;
        return 0;
    }
    for (int i = 1; i * i <= y; i++)
    {
        if (y % i == 0)
        {
            int tmp1 = i + 2;
            int tmp2 = (y / i) + 2;
            if (tmp1 * 2 + tmp2 * 2 - 4 == g)
            {
                cout << tmp1 << " " << tmp2;
                return 0;
            }
        }
    }
}