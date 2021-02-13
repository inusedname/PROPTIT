#include <stdio.h>

int main()
{
    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);
    if (a==b&&b==c)
    {
        printf("Tam giac deu.");
        return 0;
    }
    if (b>a)
    {
        int i = a;
        a = b;
        b = i;
    }
    if (c>a)
    {
        int i = a;
        a = c;
        c = i;
    }
    if (b+c<a)
    {
        printf("Day khong la tam giac");
        return 0;
    }
    int flag = 0;
    if (a==b||b==c||a==c)
        flag++;
    if (b*b+c*c==a*a)
        flag += 2;
    switch (flag)
    {
        case 1 :
            printf("Day la tam giac can");
            break;
        case 2 :
            printf("Day la tam giac vuong");
            break;
        case 3 :
            printf("Day la tam giac vuong can");
            break;
        default :
            printf("Day la tam giac thuong");
            break;
    }
}