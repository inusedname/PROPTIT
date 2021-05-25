#include <iostream>
#include <math.h>
using namespace std;

double dequi(int n)
{
    if (n==1)
        return 1;
    return n + sqrt(dequi(n - 1));
}
int main()
{
    int n;
    cin >> n;
    cout << sqrt(dequi(n));
}