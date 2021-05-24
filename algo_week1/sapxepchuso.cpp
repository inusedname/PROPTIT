#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
int partition(int left, int right, vector<int> &a)
{
    int pivot = a[right];
    int addpivot = right;
    right--;
    while (1)
    {
        while (left <= right && a[left] < pivot)
            left++;
        while (left <= right && a[right] > pivot)
            right--;
        if (left >= right)
            break;
        swap(a[left], a[right]);
        left++;
        right--;
    }
    swap(a[left], a[addpivot]);
    return left;
}
void quicksort(int left, int right, vector<int> &a)
{
    if (left < right)
    {
        int pi = partition(left, right, a);
        quicksort(left, pi - 1, a);
        quicksort(pi + 1, right, a);
    }
}
void solve()
{
    int n;
    cin >> n;
    string s;
    int p = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
            ans.push_back(s[j] - '0');
    }
    n = ans.size();
    quicksort(0, n - 1, ans);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
}