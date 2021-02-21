#include <iostream>

using namespace std;

int main()
{
    int n;
    int l,r;
    cin >> n;
    int a[n];
    long long sum = 0;
    long long max = -99999999;
    for (int i = 0; i < n;i++)
    {
        cin >> a[i];
        if (a[i]>max)
            max = a[i];
    }
    while (a[n-1]<0)
    {
        n--;
    }
    for (int i = 0; i < n;i++)
    {
        sum = 0;
        if (a[i]<=0)
            continue;
        for (int j = i; j < n;j++)
        {    
            sum = sum + a[j];
            if (sum<0)
            {
                i = j;
                break;
            }
            if (sum == max&&(i+j<l+r))
            {
                i = l;
                j = r;
            }
            if (sum>max)
            {
                max = sum;
                l = i;
                r = j;
            }
        }
    }
    cout << l + 1 << " " << r + 1 << " " << max;
}