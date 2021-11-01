#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int oo = 1e9 + 7;
using namespace std;

int MIN = 9999999;

int opA(int n)
{
    int u = sqrt(n);
    return n - u * u;
}
int opB(int n)
{
    int absolute = 0;
    int answer;
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            int u = opA(n / i);
            if (u < absolute)
            {
                absolute = u;
                answer = n / i;
            }
        }
    }
    return answer;
}
void calculate(int n, int step)
{
    if (n > 1)
    {
        int tmp = n;
        int stepTMP = step;
        int u = opA(tmp);
        tmp -= u;
        stepTMP += u;
        calculate(tmp, stepTMP);
        step += 1;
        n = opB(n);
        calculate(n, step);
    }
    MIN = min(MIN, step);
}
void solve()
{
    int n;
    cin >> n;
    calculate(n, 0);
    cout << MIN;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}