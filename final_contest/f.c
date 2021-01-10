#include <stdio.h>
#include <math.h>

int main()
{
        double h[1003];
        double c[1003];
        double ratio[1003];
        double maxratio = 1;
        int n,i;
        scanf("%d", &n);
        long long sum = 0;
        for (i = 0; i < n;i++)
        {
            scanf("%d%d", &h[i], &c[i]);
            if (h[i]>c[i])
                ratio[i] = h[i] / c[i];
            else
                ratio[i] = c[i] / h[i];
            if (ratio[i]>maxratio)
                maxratio = ratio[i];
        }
        if (maxratio>=10000)
        {
            int maxheat = -99, maxcold = -99;
            for (i = 0; i < n;i++)
            {
                if(ratio[i]>=10000)
                {
                    if(h[i]>maxheat)
                        maxheat = h[i];
                    if(c[i]>maxcold)
                        maxcold = c[i];
                }
            }
            sum = sum + (maxheat * maxcold);
        }
        if (maxratio>=1000)
        {
            int maxheat = -99, maxcold = -99;
            for (i = 0; i < n;i++)
            {
                if(ratio[i]>=1000&&ratio[i]<10000)
                {
                    if(h[i]>maxheat)
                        maxheat = h[i];
                    if(c[i]>maxcold)
                        maxcold = c[i];
                }
            }
            sum = sum + (maxheat * maxcold);
        }
        printf("%d\n", maxratio);
        if (maxratio>=100)
        {
            int maxheat = -99, maxcold = -99;
            for (i = 0; i < n;i++)
            {
                if(ratio[i]>=100&&ratio[i]<1000)
                {
                    if(h[i]>maxheat)
                        maxheat = h[i];
                    if(c[i]>maxcold)
                        maxcold = c[i];
                }
            }
            sum = sum + (maxheat * maxcold);
        }
        printf("100: %lld\n", sum);
        if (maxratio>=10)
        {
            int maxheat = -99, maxcold = -99;
            for (i = 0; i < n;i++)
            {
                if(ratio[i]>=10&&ratio[i]<100)
                {
                    if(h[i]>maxheat)
                        maxheat = h[i];
                    if(c[i]>maxcold)
                        maxcold = c[i];
                }
            }
            sum = sum + (maxheat * maxcold);
        }
        printf("10: %d\n", sum);
        if (maxratio>0)
        {
            int maxheat = -99, maxcold = -99;
            for (i = 0; i < n;i++)
            {
                if(ratio[i]>0&&ratio[i]<10)
                {
                    if(h[i]>maxheat)
                        maxheat = h[i];
                    if(c[i]>maxcold)
                        maxcold = c[i];
                }
            }
            sum = sum + (maxheat * maxcold);
        }
        printf("1: %d\n", sum);
        printf("%d\n",sum);
}