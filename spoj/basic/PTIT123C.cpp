#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";

struct mem
{
    int price;
    int day;
};
bool cmp(mem x, mem y)
{
    return x.price < y.price;
}
bool cmp1(mem x, mem y)
{
    return x.day < y.day;
}
bool cmp2(mem x, mem y)
{
    return x.day > y.day;
}
void solve()
{
    int dem = 1;
    while (1)
    {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        if (n == 0 && k1 == 0 && k2 == 0)
            break;
        vector<mem> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].price;
            a[i].day = i + 1;
        }
        sort(a.begin(), a.end(), cmp);
        cout << "Case " << dem << endl;
        sort(a.begin(), a.begin() + k1, cmp1);
        sort(a.end() - k2, a.end(), cmp2);
        for (int i = 0; i < k1; i++)
            cout << a[i].day << " ";
        cout << endl;
        for (int i = n - k2; i < n; i++)
            cout << a[i].day << " ";
        cout << endl;
        dem++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}