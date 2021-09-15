#include <iostream>
#include <queue>
#define ll long long
#define endl "\n"
using namespace std;

#define pli pair<ll, int>
struct cmp
{
    bool operator()(pli a, pli b) { return a.first < b.first; }
};

priority_queue<pli, vector<pli>, cmp> pq;

void sinh68()
{
    queue<pli> q;
    q.push({6, 1});
    q.push({8, 1});
    while (!q.empty())
    {
        
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        cout << endl;
    }
}