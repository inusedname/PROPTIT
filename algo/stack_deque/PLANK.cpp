#include <iostream>
#include <stack>
using namespace std;
long long MAX(long long a, long long b)
{
    if (a > b)
        return a;
    return b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, tmp;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stack<int> st;
    int L[n + 1], R[n + 1];
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (st.empty())
            L[i] = 0;
        else
            L[i] = st.top() + 1;
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (st.empty())
            R[i] = n;
        else
            R[i] = st.top();
        st.push(i);
    }
    // for (int i = 0; i < n; i++)
    //     cout << L[i] << " ";
    // cout << endl;
    // for (int i = 0; i < n; i++)
    //     cout << R[i] << " ";
    long long res = -1;
    for (int i = 0; i < n; i++)
    {
        int k = R[i] - L[i];
        if (k >= a[i])
            res = MAX(res, a[i]);
        else
            res = MAX(res, k);
    }
    cout << res * res;
}