#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    long long square = 1;
    int i;
    for (i = 0; i < n;i++)
        square = square * 2;
    square--;
    printf("%lld", ((1 + square) / 2) * square);
}