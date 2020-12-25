#include <stdio.h>
int main()
{
    int test;
    scanf("%d", &test);
    while (test>0)
    {
        int a[100001];
        int n, i;
        scanf("%d", &n);
        for (i = 0; i < n;i++)
        {
            scanf("%d", &a[i]);
        }
        int first = -1000000;
        for (i = 0; i < n;i++)
        {
            if(first<a[i])
                first = a[i];
        }
        int second = -1000000;
        for (i = 0; i < n;i++)
        {
            if(second<a[i])
            {   
                if (a[i]==first)
                    continue;
                second = a[i];
            }
        }
        printf("%d %d\n", second, first);
        test--;
    }
}