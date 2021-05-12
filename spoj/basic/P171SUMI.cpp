#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
string s;
void solve()
{
    cin >> s;
    int freq[27] = {0};
    for (int i = 0; i < s.size(); i++)
        freq[s[i] - 'a']++;
    int demle = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] % 2)
            demle++;
    if (demle > 3)
        cout << "NO";
    else
        cout << "YES";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}