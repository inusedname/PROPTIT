#include <stdio.h>
#include <ctype.h>

int main()
{
    int n;
    scanf("%d", &n);
    char a[n];
    scanf("%s", &a);
    for (int i = 0; i < n;i++)
    {
        if (islower(a[i]))
            a[i] = toupper(a[i]);
    }
    printf("%s", a);
}