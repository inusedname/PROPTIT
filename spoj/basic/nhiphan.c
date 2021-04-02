#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a = pow(2, n);
    for (int i = 0; i < a;i++)
    {
        int a[9] = {0};
        int ptr = 0;
        int j = i;
        while (j>1)
        {
            a[ptr++] = j % 2;
            j /= 2;
        }
        if (j==1)
            a[ptr] = 1;
        for (int j = n - 1; j >= 0;j--)
            printf("%d", a[j]);
        printf("\n");
    }
}