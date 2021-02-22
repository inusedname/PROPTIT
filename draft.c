#include <stdio.h>

int main()
{
    int route;
    scanf("%d", &route);
    int min = 99999;
    while (route)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a+b<min)
            min = a + b;
        route--;
    }
    printf("%d", min);
}