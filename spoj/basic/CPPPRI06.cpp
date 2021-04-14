#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
void nto()
{
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int b[t];
    int max = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> b[i];
        if (b[i] > max)
            max = b[i];
    }
    max++;
    int a[max];
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i < max; i++)
        a[i] = 1;
    for (int i = 2; i * i <= max; i++)
    {
        if (a[i])
        {
            for (int j = i * i; j < max; j += i)
                a[j] = 0;
        }
    }
    for (int i = 0; i < t; i++)
    {
        for (int j = 2; j <= b[i]; j++)
        {
            if (a[j])
                if (a[b[i] - j])
                {
                    cout << j << " " << b[i] - j << endl;
                    break;
                }
        }
    }
}