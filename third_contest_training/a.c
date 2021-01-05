#include <stdio.h>
int main()
{
    int test;
    scanf("%d", &test);
    while (test>0)
    {
        int a[100005];
        int n, i;
        scanf("%d", &n);
        int max, min=-1000000;
        int flag = 0;
        for (i = 0; i < n;i++)
        {
            scanf("%d", &a[i]);
            if (i==0)
                max = a[0];
            if (a[i]==max)
            {
                flag++;
                continue;
            }
            else if (a[i] > max)
            {
                min = max;
                max = a[i];
            }
            else if (a[i] > min)
                min = a[i];
        }
        if (flag!=n)
        printf("%d %d\n", min, max);
        else
            printf("0\n");
        test--;
    }
}