#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if ((a==1&&b==3)||(a==3&&b==1))
    {
        printf("1.000.000 VND");
        return 0;
    }
    int sum = 0;
    switch (a)
    {
        case 1:
        case 2:
            sum = sum + 100;
            break;
        case 3:
        case 4:
            sum = sum + 50;
            break;
    }
    switch (b)
    {
        case 1:
        case 2:
            sum = sum + 100;
            break;
        case 3:
        case 4:
            sum = sum + 50;
            break;
    }
    printf("%d.000 VND", sum);
}