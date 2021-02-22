#include <stdio.h>
#include <math.h>
int main()
{
    double x1, y1, x, y, r;
    scanf("%lf%lf%lf%lf%lf", &x, &y, &x1, &y1, &r);
    double d = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
    int dem = 0;
    while (d>2*r)
    {
        d = d - (2 * r);
        dem++;
    }
    if(d)
        dem++;
    printf("%d", dem);
}