#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int n, k;
deque<int> dq; //deque lưu index

void minCalc(vector<int> a, int n, vector<int> &minRange)
{
    for (int i = 0; i < n; i++)
    {
        while (dq.size() && a[dq.back()] > a[i])
            dq.pop_back();
        dq.push_back(i);
        if (dq.front() + k <= i)
            dq.pop_front();
        if (i + 1 >= k)
            minRange.push_back(a[dq.front()]);
    }
}
void maxCalc(vector<int> a, int n, vector<int> &maxRange)
{
    for (int i = 0; i < n; i++)
    {
        while (dq.size() && a[dq.back()] < a[i])
            dq.pop_back();
        dq.push_back(i);
        if (dq.front() + k <= i)
            dq.pop_front();
        if (i + 1 >= k)
            maxRange.push_back(a[dq.front()]);
    }
}
int main()
{
    cin >> n >> k;
    vector<int> a(n);
    vector<int> minRange;
    vector<int> maxRange;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    minCalc(a, n, minRange);
    dq.resize(0);
    maxCalc(a, n, maxRange);
    for (int i = 0; i < minRange.size(); i++)
        cout << minRange[i] << " " << maxRange[i] << "\n";
    return 0;
}