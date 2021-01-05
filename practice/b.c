#include <stdio.h>
int freq[2000000] = {0};
int main()
{
    int n; 
    scanf("%d", &n);
    int i;
    int a[100006];
    a[0] = 0;
    for (i = 1; i < n;i++)
    {
        scanf("%d", &a[i]);    
        if (!a[i])
        {
            printf("-1");
            return 0;
        }
    }
    freq[0] = 1;
    for (i = 1; i < n;i++)
    {
        a[i] = a[i] + a[i - 1];
        if (!freq[a[i]])
            freq[a[i]]++;
        else
        {
            printf("-1");
            return 0;
        }
    }
    int min = 0;
    for (i = 1; i < n;i++)
        if ( a[i] < min )
            min = a[i];
    for (i = 0; i < n;i++)
        printf("%d ", a[i] - min + 1);
}