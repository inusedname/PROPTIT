// https : //www.spoj.com/PTIT/problems/PTIT013A
#include <stdio.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        getchar();
        char a[20];
        scanf("%s", a);
        if (a[strlen(a) - 1] == '6' && a[strlen(a) - 2] == '8')
            printf("1");
        else
            printf("0");
        printf("\n");
    }
}