#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
int toDecimal (char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
    return -1;
}
int main()
{
    string s;
    cin >> s;
    int before = 0, after;
    long long sum = 0;
    for (int i = 0; i < s.length();i++)
    {
        after = toDecimal(s[i]);
        if (after>before)
            sum = sum + after - 2*before;
        else
            sum = sum + after;
        before = after;
    }
    printf("%d", sum);
}