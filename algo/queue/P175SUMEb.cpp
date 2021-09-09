#include <iostream>
#include <queue>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    queue<pair<int, int>> a;
    for (int i = 1; i <= 5; i++)
        a.push({i, 1});
    while (n > a.front().second)
    {
        n -= a.front().second;
        a.push({a.front().first, a.front().second * 2});
        a.pop();
    }
    cout << a.front().first;
}