#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

vector<int> a;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        a.clear(), a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> b = a;
        sort(a.begin(), a.end());
        int l = 0, r = n - 1;
        while (a[l] == b[l])
            l++;
        while (a[r] == b[r])
            r--;
        cout << l + 1 << " " << r + 1;
        cout << endl;
    }
}