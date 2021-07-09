#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if (a == 0)
        if (b == 0)
            if (c == 0)
                printf("INF");
            else
                printf("NO");
        else if (c == 0)
            printf("0.00");
        else
            printf(".2lf", -c / b);
    else
    {
        double d = (b * b) - (4 * a * c);
        if (d < 0)
            printf("NO");
        else if (d == 0)
            if (b == 0)
                printf("0.00");
            else
                printf("%.2lf", -b / (2.0 * a));
        else
        {
            double x1 = (-b - sqrt(d)) / (2.0 * a);
            if (x1 == 0)
                x1 = abs(x1);
            double x2 = (-b + sqrt(d)) / (2.0 * a);
            if (x2 == 0)
                x2 = abs(x2);
            if (x1 > x2)
                printf("%.2lf %.2lf", x2, x1);
            else
                printf("%.2lf %.2lf", x1, x2);
        }
    }
}