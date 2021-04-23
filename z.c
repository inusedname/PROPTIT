#include <stdio.h>

int main()
{
    int x, y, z;
    int m;
    scanf("%d%d%d%d", &x, &y, &z, &m);
    m *= 2;
    int dem = 0;
    for (int i = 1; i <= z; i++)
    {
        if (m < 3)
            break;
        m -= 3;
        dem++;
        if (m == 0)
        {
            printf("%d", dem);
            return 0;
        }
    }
    for (int i = 1; i <= y; i++)
    {
        if (m < 2)
            break;
        m -= 2;
        dem++;
        if (m == 0)
        {
            printf("%d", dem);
            return 0;
        }
    }
    for (int i = 1; i <= x; i++)
    {
        m -= 1;
        dem++;
        if (m == 0)
        {
            printf("%d", dem);
            return 0;
        }
    }
    printf("KHONG DOI DUOC");
}