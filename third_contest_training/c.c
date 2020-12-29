#include <stdio.h>
#define MAX 1000000
int a[100000];
int freq[10000]={0};
int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        freq[a[i]]++;
    }
    int ans = 0;
    int loc = 0;
    for (i = 0; i< MAX;i++)
    {
        if (freq[i]>ans)
        {
            ans = freq[i];
            loc = i;
        }
    }
    printf("%d %d", loc, ans);
}