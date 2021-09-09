#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"
using namespace std;
struct data
{
    ll index;
    ll front;
    ll back;
};
vector<data> v;
data tmp{1, 1, 5};

void init()
{
    while (tmp.back <= (ll)1e9)
    {
        v.push_back(tmp);
        tmp.index *= 2;
        tmp.front = tmp.back + 1;
        tmp.back = tmp.front + tmp.index * 5 - 1;
    }
}

int main()
{
    init();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    for (int i = 0; i < v.size(); i++)
        if (n <= v[i].back)
        {
            n -= v[i].front;
            cout << (n / v[i].index) + 1;
            break;
        }
}
