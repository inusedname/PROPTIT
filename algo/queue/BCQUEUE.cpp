#include <iostream>
#include <queue>
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    int n;
    int tmp;
    queue<int> q;
    while (t--)
    {
        cin >> n;
        switch (n)
        {
        case 1:
            cout << q.size() << endl;
            break;
        case 2:
            (q.empty()) ? (cout << "YES\n") : (cout << "NO\n");
            break;
        case 3:
            cin >> tmp;
            q.push(tmp);
            break;
        case 4:
            if (!q.empty())
                q.pop();
            break;
        case 5:
            (q.empty()) ? (cout << "-1") : (cout << q.front());
            cout << endl;
            break;
        case 6:
            (q.empty()) ? (cout << "-1") : (cout << q.back());
            cout << endl;
            break;
        }
    }
}