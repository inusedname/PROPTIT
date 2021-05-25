#include <stdio.h>
int f[100005]={0};
int main()
{
    unsigned long long n;
    int i;
    scanf("%d",&n);
    int t;
    unsigned long long sum = 0;
    for (i=0;i<n;i++)
    {
        scanf("%d",&t);
        if (t>n||t==0)
        {
        	printf ("NO");
        	return 0;
		}
        f[t]++;
    }
    for (i=1;i<=n;i++)
        if (f[i]!=1)
        {
            printf ("NO");
            return 0;
        }
    if (n%2==0)
        sum = (n/2)*(n+1);
    else
        sum = ((n + 1) / 2) * n;
    printf("YES %llu", sum);
}