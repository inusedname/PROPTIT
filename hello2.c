#include <stdio.h>
#include <string.h>
int main()
{
    int i, n ,dem = 0;
    scanf("%d", &n);
    char panel[10];
    int seats;
    long long travel;
    float tbc = 0;
    int max = 0;
    int point;
    for (i = 0; i < n;i++)
    {
        scanf("%s %d %lld", panel, &seats, &travel);
        printf("%s %d %lld", panel, seats, travel);
        if (panel[0]=='2'&&panel[1]=='9')
        {
            dem++;
            tbc = tbc + (float)seats;
        }
        if (seats<16) 
            if (travel>max)
            {
                point = i;
                max = travel;
            }
    }
    tbc = tbc / dem;
    printf("%f %d", tbc, max);
}