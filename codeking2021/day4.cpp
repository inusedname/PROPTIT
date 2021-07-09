#include <iostream>
#include <vector>
#include <string>
const int oo = 1e9;
using namespace std;

vector<int> a;
string s;
void solve()
{
    int n, tmp, max = 0;
    cin >> n;
    a.clear();
    a.resize(0);
    s.clear();
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        tmp = s[i] - '0';
        if (tmp > max)
            max = tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < a.size(); i++)
    {
        while (a[i] < max)
        {
            if (i < a.size() - 1)
            {
                a[i] += a[i + 1];
                a.erase(a.begin() + i + 1);
            }
            else
            {
                a[i - 1] += a[i];
                a.erase(a.begin() + i);
                i--;
            }
            if (a[i] > 9)
            {
                cout << "NO";
                return;
            }
            if (a[i] > max)
            {
                max = a[i];
                i = 0;
            }
        }
    }
    if (a.size() == 1)
        cout << "NO";
    else
        cout << "YES";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}