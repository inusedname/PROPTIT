#include <iostream>
#include <queue>
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int k;
        cin >> k >> s;
        int f['Z' - 'A' + 1] = {0};
        for (auto i : s)
        {
            f[i - 'A']++;
        }
        priority_queue<int> pq;
        for (auto i : f)
        {
            if (i)
                pq.push(i);
        }
        while (pq.top() != 0 && k)
        {
            int tmp = pq.top();
            pq.pop();
            int MIN = min(k, tmp - pq.top());
            pq.push(tmp - MIN);
            k -= MIN;
        }
        ll res = 0;
        while (!pq.empty())
        {
            res += (ll)pq.top() * pq.top();
            pq.pop();
        }
        cout << res;
        cout << endl;
    }
}