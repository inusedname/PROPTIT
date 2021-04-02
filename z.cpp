#include <iostream>
using namespace std;

int main()
{
    string a;
    string b;
    getline(cin, a);
    getline(cin, b);
    int sum[1000];
    int nho = 0;
    int j = 0;
    if (a.size() < b.size())
    {
        int q = b.size() - a.size();
        for (int i = 0; i < q; i++)
            a = "0" + a;
    }
    else if (a.size() > b.size())
    {
        int q = a.size() - b.size();
        for (int i = 0; i < q; i++)
            b = "0" + b;
    }
    for (int i = a.size() - 1; i >= 0; i--)
    {
        int tmp = a[i] - '0' + b[i] - '0';
        sum[j] = (tmp + nho) % 10;
        if (tmp + nho > 9)
            nho = (tmp + nho) / 10;
        else
            nho = 0;
        j++;
    }
    if (nho != 0)
    {
        sum[j++] = nho;
    }
    for (int i = j - 1; i >= 0; i--)
        printf("%d", sum[i]);
}