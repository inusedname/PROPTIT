//https://www.spoj.com/PTIT/problems/BCLUCKY1/
#include <stdio.h>
#include <string.h>
int main()
{
    char a[20];
    scanf("%s", a);
    if (strlen(a) != 4 && strlen(a) != 7)
    {
        printf("NO");
        return 1;
    }
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] != '4' && a[i] != '7')
        {
            printf("NO");
            return 1;
        }
    }
    printf("YES");
}