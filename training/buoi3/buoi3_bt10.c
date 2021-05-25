#include <stdio.h>
#include <windows.h>
int main()
{
    int a, b, temp;
    int flag;
    long long sum = 0;
    scanf("%d%d", &a, &b);
    for (a; a <= b;a++)
    {
        flag = 1;
        for (temp = 2; temp < a;temp++)
            {
                if (a%temp==0)
                {
                    flag = 0;
                    break;
                }
            }
        if (flag==1)
        {
            sum = sum + a;
            printf("%d ", a);
        }
    }
    printf("\b\n%d", sum);
}