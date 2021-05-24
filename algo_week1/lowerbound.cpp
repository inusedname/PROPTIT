#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"

void solve()
{
    vector<int> a = {1, 2, 2, 2, 5};
    int low = lower_bound(a.begin(), a.end(), 2) - a.begin();
    int high = upper_bound(a.begin(), a.end(), 2) - a.begin();
    cout << "Phan tu dau tien nho hon hoac bang 2: " << low << endl; // 1
    cout << "Phan tu dau tien lon hon 2: " << high << endl; // 4
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