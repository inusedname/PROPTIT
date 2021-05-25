#include <stdio.h>

int main()
{
    long long n,sum=0;
    int du;
    scanf("%d", &n);
    for(int i=n; i!=0; i=i/10)
    {
        du = i%10;
        sum = sum + du; 
    }
    printf("%d",sum);
}
