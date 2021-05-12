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
    int n;
    cin >> n;
    vector<int> base(n);
    for (int i = 0; i < n; i++)
        cin >> base[i];
    int count = 0;
    for (int i = 0; i < n - 1; i++)
        if (base[i] <= base[i + 1])
            count++;
    if (count == n - 1)
    {
        cout << 0;
        return;
    }
    int min = base[0];
    for (int i = 0; i < n - 1; i++)
    {
        if (base[i] > base[i + 1])
        {
            if (base[i + 1] <= min)
            {
                for (int j = i + 1; j < n - 1; j++)
                    if (base[j] > base[j + 1])
                    {
                        cout << -1;
                        return;
                    }
                count = n - i - 1;
                break;
            }
            else
            {
                cout << -1;
                return;
            }
        }
    }
    if (base[n - 1] > min)
        cout << -1;
    else
        cout << count;
    // sort(clone.begin(), clone.end());
    // int count = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (base[0] == clone[0])
    //     {
    //         if (base == clone)
    //         {
    //             cout << count;
    //             break;
    //         }
    //     }
    //     base.insert(base.begin(), base[n - 1]);
    //     base.resize(n);
    //     // for (int i = 0; i < n; i++)
    //     //     cout << base[i];
    //     // cout << endl;
    //     count++;
    // }
    // if (count == n)
    //     cout << -1;
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