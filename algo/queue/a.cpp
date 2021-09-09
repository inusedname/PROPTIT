#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define ll long long
#define endl "\n"
using namespace std;

struct mem
{
    char al;
    int f;
};

struct cmp
{
    bool operator()(mem x, mem y) { return x.f < y.f; };
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    priority_queue<mem, vector<mem>, cmp> qu;
    mem tmp;
    int k;
    string s;
    while (t--)
    {
        s.erase();
        cin >> k >> s;
        sort(s.begin(), s.end());
        tmp = {s[0], 1};
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == tmp.al)
                tmp.f++;
            else
            {
                qu.push(tmp);
                tmp.al = s[i];
                tmp.f = 1;
            }
        }
        qu.push(tmp);
        while (k--)
        {
            tmp = qu.top();
            tmp.f--;
            qu.pop();
            qu.push(tmp);
        }
        ll sum = 0;
        while (!qu.empty())
        {
            tmp = qu.top();
            sum += (tmp.f * tmp.f);
            qu.pop();
        }
        cout << sum;
        cout << endl;
    }
}