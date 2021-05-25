#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    while (a>0)
    {
        if (a<b)
        {
            int c = a;
            a = b;
            b = c;
        }
        a = a % b;
    }
    printf("%d", b);
}