#include <stdio.h>

int count(int a[10000],int n, int i)
{
    int j;
    int dem = 0;
    for (j = 0; j < n;j++)
    {
        if (a[j]==i)
            dem++;
    }
    return dem;
}
int main()
{
    int n, i;
    scanf("%d", &n);
    int a[100000];
    for (i = 0; i < n;i++)
    {
        scanf("%d", &a[i]);
    }
    int time = 0;
    int number = 0;
    int B[10] = {0};
    for (i = 0; i < n;i++)
    {
        if ()
    }
}