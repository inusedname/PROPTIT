#include <stdio.h>
#include <stdlib.h>

int n, x, mid;
int a[1000005];
void binary(int left, int right)
{
    if (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid] == x)
        {
            printf("YES");
            exit(0);
        }
        if (a[mid] > x)
            binary(left, mid - 1);
        else
            binary(mid + 1, right);
    }
    printf("NO");
    exit(0);
}
int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    binary(0, n - 1);
}