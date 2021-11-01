#include <bits/stdc++.h>
using namespace std;

bool flag = 0;
void in(string s)
{
    for (int i = 0; i < s.size() - 1; i++)
        if (s[i] == s[i + 1])
            return;
    flag = 1;
    cout << s << endl;
}
int main()
{
    int i;
    int min;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int n = s.size();
    string hv = s;
    in(hv);
    while (1)
    {
        for (i = n - 2; i >= 0; i--)
        {
            if (i < 0)
                break;
            if (hv[i] < hv[i + 1])
                break;
        }
        if (i < 0)
            break;
        min = hv[i];
        for (int j = n - 1; j > i; j--)
            if (hv[j] > hv[i])
            {
                swap(hv[i], hv[j]);
                break;
            }
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            swap(hv[l], hv[r]);
            l++, r--;
        }
        in(hv);
    }   
    if (!flag)
        cout << "INVALID";
}