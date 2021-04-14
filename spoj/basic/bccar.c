#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, tmp;
        scanf("%d", &n);
        int min = 99;
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            if (tmp < min)
                min = tmp;
            if (tmp > max)
                max = tmp;
        }
        printf("%d\n", 2 * (max - min));
    }
}