#include <stdio.h>

int main()
{
    int t;
    int a[1003];
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int max = -1e6;
        int ans[n], p = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            if (a[j] > max)
            {
                ans[p] = a[j], p++;
                max = a[j];
            }
        }
        for (int i = p - 1; i >= 0; i--)
            printf("%d ", ans[i]);
        printf("\n");
    }
}