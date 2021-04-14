#include <stdio.h>

int main()
{
    int a, b, c;
    while (1)
    {
        printf("\n");
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0)
            break;
        if (c > a && c > b)
        {
            if (c * c == a * a + b * b)
                printf("right");
            else
                printf("wrong");
            continue;
        }
        if (a > b && a > c)
        {
            if (a * a == b * b + c * c)
                printf("right");
            else
                printf("wrong");
            continue;
        }
        if (b > a && b > c)
        {
            if (b * b == a * a + c * c)
                printf("right");
            else
                printf("wrong");
            continue;
        }
    }
}