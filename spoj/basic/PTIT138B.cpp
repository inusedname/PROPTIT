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
    string cha;
    string con;
    int tuoi;
};
bool cmp(mem x, mem y)
{
    if (x.tuoi == y.tuoi)
    {
        return x.con < y.con;
    }
    return x.tuoi > y.tuoi;
}
int dem = 1;
void solve()
{
    int n;
    cin >> n;

    vector<mem> list(n);
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cin >> list[i].cha;
        cin >> list[i].con;
        cin >> list[i].tuoi;
    }
    for (int i = 0; i < n; i++)
    {
        if (list[i].cha == "Ted")
            list[i].tuoi = 100 - list[i].tuoi;
    }
    for (int i = 0; i < n; i++)
    {
        if (list[i].cha != "Ted")
        {
            int j;
            for (j = 0; j < n; j++)
            {
                if (list[i].cha == list[j].con)
                    break;
            }
            list[i].tuoi = list[j].tuoi - list[i].tuoi;
        }
    }
    sort(list.begin(), list.end(), cmp);
    cout << "DATASET " << dem << endl;
    for (int i = 0; i < n; i++)
    {
        cout << list[i].con << " " << list[i].tuoi << endl;
    }
    dem++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}