#include <stdio.h>

int main()
{
    int m;
    scanf("%d", &m);
    if(m<11)
        printf("%d000", m);
    else if(m<21)
        printf("%d000", 10 + (m-10) * 2);
    else if(m<31)
        printf("%d000", 30 + (m-20) * 3);
    else
        printf("%d000", 60 + (m-30) * 4);
}
//sqrt_abs_fabs
//if_else
//switchcase
