#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long dem;
    if (abs(n-k)>n)
    {
        cout << "0";
        return 0;
    }
    if (n<k)
        dem = floor(k / 2) - abs(n - k) + 1;
    if (n>=k)
        dem = floor(k / 2);
    if (k%2==0&&k/2<=n)
        dem--;
    if (dem<0)
        dem = 0;
    cout << dem;
}