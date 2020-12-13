#include <stdio.h>
#include <math.h>
int main()
{
    /*
    int v;
    float t;
    scanf("%d %f", &v, &t);
    printf("%.2f\n", (float)v * t);

    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n",(long long) (a + b) * (b - a + 1) / 2);
    */

    int x1, y1, x2, y2, x3, y3;
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    double s = 0.5 * ((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
    if (s > 0)
    {
        printf("%lf", s);
    }
    else
        printf("%lf", -s);
}