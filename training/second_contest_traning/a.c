#include<stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    while (a>0)
    {
        if (a<b)
        {
            int tam = a;
            a = b;
            b = tam;
        }
        a = a % b;
    }
    printf("%d", b);
}