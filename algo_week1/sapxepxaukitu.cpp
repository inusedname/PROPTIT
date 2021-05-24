#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
string s;
vector<string> word;
vector<int> num;
vector<bool> type;
int stringtoNum(string s)
{
    int dd = 0, i = 0, res = 0;
    if (s[0] == '-')
    {
        dd = 1;
        i++;
    }
    for (; i < s.size(); i++)
        res = res * 10 + int(s[i] - '0');
    if (dd)
        res = -res;
    return res;
}
int check(string s) // kiểm tra số - chữ
{
    for (int i = 0; i < s.size(); i++)
        if (isdigit(s[i]))
            return 0;
    return 1;
}
void solve()
{
    word.clear();
    num.clear();
    type.clear();
    while (cin >> s)
    {
        int brake = 0;
        if (s[s.size() - 1] == '.')
            brake = 1;
        s.erase(s.end() - 1);
        bool flag = check(s);
        if (flag)
            word.push_back(s);
        else
            num.push_back(stringtoNum(s));
        type.push_back(flag);
        if (brake)
            break;
    }
    sort(word.begin(), word.end());
    sort(num.begin(), num.end());
    int posiWord = 0, posiNum = 0;
    for (int i = 0; i < type.size() - 1; i++)
    {
        if (type[i])
            cout << word[posiWord++] << ", ";
        else
            cout << num[posiNum++] << ", ";
    }
    if (type[type.size() - 1])
        cout << word[posiWord++] << ".";
    else
        cout << num[posiNum++] << ".";
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