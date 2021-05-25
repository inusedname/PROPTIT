#include<stdio.h>
#include<math.h>
int main()
{
    int n, i;
    int dem = 1;
    scanf("%d", &n);
    for (i = 2; i <= sqrt(n);i++)
        if(n%i==0)
        {
            dem = 0;
            break;
        }
    if (!dem)
        {printf("No");}
    else
    {
        printf("Yes");
    }
    
}