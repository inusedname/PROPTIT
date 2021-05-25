#include <iostream>
#include <algorithm>
using namespace std;
int a[10002];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    sort(a, a + n);
    int dem = 0;
    int ans = -1, i=0, temp;
    while (dem<k&&i<n)
    {
        temp = a[i];
        if (temp!=ans)
        {   
            dem++;
            ans = temp;
        }
        i++;
    }
    if (dem<k)
        ans = -1;
    cout << ans;
}