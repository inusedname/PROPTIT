#include <iostream>
using namespace std;
int dd[10] = {0};
int a[10];
int n;
void IN()
{
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << " ";
}
void dequi(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (dd[i] == 0)
        {
            dd[i] = 1;
            a[k] = i;
            if (k == n)
                IN();
            else
                dequi(k + 1);
            dd[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    dequi(1);
}