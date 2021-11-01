#include <bits/stdc++.h>
#define ll long long
#define arraycin(n)             \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define endl "\n"
const int oo = 1e9 + 7;
using namespace std;

vector<int> prime{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};
int l = prime.size();
int s, k, p;
int res = 0;
void dequi(int sum, int level, int index)
{
    if (sum > s || level > k || index == prime.size())
        return;
    if (sum == s && level == k)
    {
        res++;
        return;
    }
    dequi(sum + prime[index], level + 1, index + 1);
    dequi(sum, level, index + 1);
}
void solve()
{
    cin >> s >> k >> p;
    dequi(0, 0, 0);
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}