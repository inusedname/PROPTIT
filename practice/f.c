#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t)
    {
        int i, n, words, temp;
        scanf("%d", &n);
        int max = 1, dem = 1;
        scanf("%d", &words);
        for (i = 1; i < n;i++)
        {
            scanf("%d", &temp);
            if (temp>words)
            {    
                dem++;
                if (dem>max)
                    max = dem;
            }
            else dem = 1;
            words = temp;
        }
        printf("%d\n",max);
        t--;
    }
    
}