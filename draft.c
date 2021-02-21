#include <stdio.h>
int main(void) {
    int a[1002];
    int n, k;
    int chiaHet = 0;
    int temp;
    int i, j = 0;
    int khongChia = 0;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n;i++)
    {       
        scanf("%d", &temp);
        if (temp%k==0)
            chiaHet++;
        else 
        {
            khongChia += temp;
            a[j] = temp;
            j++;
        }
    }
    int dem = j;
    if (j)
    {
        int Mod = khongChia % k;
        if (Mod) 
        {   
            for (i = 0; i < j;i++)
            {
                if (a[i]%k==Mod)
                {
                    dem--;
                    break;
                }
            }
            if (dem==j)
                dem = 0;
        }
    }
    printf("%d", chiaHet + dem);
    return 0;
}