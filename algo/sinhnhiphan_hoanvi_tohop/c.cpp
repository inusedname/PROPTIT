#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
int a[1000];

void solve()
{
    int n;
    cin >> n;
    int flag = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 2; i >= 0; i--)
        if (a[i] < a[i + 1])
        {
            for (int j = n - 1; j > i; j--)
                if (a[j] > a[i])
                {
                    swap(a[j], a[i]);
                    break;
                }
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                swap(a[l], a[r]);
                l++;
                r--;
            }
            for (int i = 0; i < n; i++)
                printf("%d ", a[i]);
            flag = 1;
            break;
        }
    if (flag == 0)
        for (int i = n - 1; i >= 0; i--)
            printf("%d ", a[i]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        printf("\n");
    }
}