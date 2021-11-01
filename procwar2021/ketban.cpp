#include <bits/stdc++.h>
#define ll long long
#define arraycin(n)             \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define endl "\n"
#define pss pair<string, string>
const int oo = 1e9 + 7;
using namespace std;

bool binsearch(vector<string> a, int start, int end, string target)
{
    while (start <= end)
    {
        int m = (start + end) / 2;
        if (a[m] == target)
            return 1;
        if (a[m] > target)
            end = m - 1;
        else
            start = m + 1;
    }
    return 0;
}
void solve()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<pss> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    string me;
    cin >> me;
    vector<string> myFriend;
    for (int i = 0; i < n; i++)
    {
        if (a[i].first == me)
            myFriend.push_back(a[i].second);
        else if (a[i].second == me)
            myFriend.push_back(a[i].first);
    }
    sort(myFriend.begin(), myFriend.end());
    string ans;
    string hisFriend;
    for (int i = 0; i < myFriend.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j].first == myFriend[i])
                hisFriend = a[j].second;
            else if (a[j].second == myFriend[i])
                hisFriend = a[j].first;
            else
                continue;
            if (hisFriend == me || (binsearch(myFriend, 0, myFriend.size() - 1, hisFriend)))
                continue;
            else if (ans.empty())
                ans = hisFriend;
            else
            {
                if (ans.size() < hisFriend.size())
                    ans = hisFriend;
                else if (ans.size() == hisFriend.size() && ans < hisFriend)
                    ans = hisFriend;
            }
        }
    }
    if (ans.empty())
        cout << "SaiDe";
    else
        cout << ans;
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