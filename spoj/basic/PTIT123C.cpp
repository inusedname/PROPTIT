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
int freq[101] = {0};
void solve()
{
    int dem = 1;
    while (1)
    {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        if (n == 0)
            break;
        vector<mem> a;
        mem tmp2;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp2.price;
            tmp2.day = i + 1;
            a.push_back(tmp2);
        }
        sort(a.begin(), a.end(), cmp);
        cout << "Case " << dem << endl;
        int count = 0;
        vector<int> u;
        for (int i = 0; i < n; i++)
        {
            if (count == k1)
                break;
            freq[a[i].price] = 1;
            u.push_back(a[i].day);
            count++;
        }
        sort(u.begin(), u.end());
        for (int i = 0; i < u.size(); i++)
            cout << u[i] << " ";
        cout << endl;
        count = 0;
        u.resize(0);
        for (int i = n - 1; i >= 0; i--)
        {
            if (freq[a[i].price] == 0)
            {
                if (count == k2)
                    break;
                u.push_back(a[i].day);
                count++;
            }
        }
        sort(u.begin(), u.end());
        for (int i = u.size() - 1; i >= 0; i--)
            cout << u[i] << " ";
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