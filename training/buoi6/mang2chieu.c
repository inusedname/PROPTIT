#include <stdio.h>

int main ()
{
    int hang, cot;
    scanf("%d %d", &hang, &cot);
    int a[100][100];
    int i, j;
    for (i = 0; i < hang;i++)
        for (j = 0; j < cot;j++)
            scanf("%d", &a[i][j]);
    for (i = 0; i < hang;i++)
    {    
        for (j = 0; j < cot;j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < cot;i++)
    {    
        for (j = 0; j < hang;j++)
            printf("%d ", a[j][i]);
        printf("\n");
    }
}