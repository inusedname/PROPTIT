#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int dem = 0;
    for (int i = 2; i <= sqrt(n);i++)
    {
        if(n%i==0)
        {
            dem++;
            break;
        }
    }
    if (dem==0)
        printf("YES"); 
    else
        printf("No");
}