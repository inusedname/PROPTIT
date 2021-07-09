#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
int n, m;
vector<int> A, P, Q;
void solve()
{
    cin >> n >> m;
    P.resize(n);
    Q.resize(m);
    A.assign(n + m, 0);
    for (int i = 0; i < n; i++)
        cin >> P[i];
    for (int i = 0; i < m; i++)
        cin >> Q[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            A[i + j] += P[i] * Q[j];
    for (int i = 0; i < n + m - 1; i++)
        cout << A[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}