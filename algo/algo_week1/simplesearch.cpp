#include <stdio.h>
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
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > k)
            break;
        int x = k - a[i];
        res += upper_bound(a.begin() + i + 1, a.end(), x) - lower_bound(a.begin() + 1, a.end() - 1, x);
    }
    printf("%d", res);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        solve();
        printf("\n");
    }
}