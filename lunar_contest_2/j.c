#include <stdio.h>
#include <math.h>

double kcach(double x0, double xb, double y0, double yb)
{
    return sqrt((x0-xb)*(x0-xb)+(y0-yb)*(y0-yb));
}
int main()
{
    double xa, ya, w, h, x0, y0, r;
    scanf("%lf %lf %lf %lf %lf %lf %lf", &xa, &ya, &w, &h, &x0, &y0, &r);
    double xi = xa + (w / 2);
    double yi = ya - (h / 2);
    double xb = xa + w, yb = ya;
    double xc = xa + w, yc = ya - h;
    double xd = xa, yd = ya - h;
    int bl = 1;
    if(fabs(yi-y0)>r+(h/2)||fabs(xi-x0)>r+(w/2))
        bl = 0;
    if (fabs(xi-x0)>w/2&&fabs(yi-y0)>h/2)
        if (kcach(x0,xa,y0,ya)>r||kcach(x0,xb,y0,yb)>r||kcach(x0,xc,y0,yc)>r||kcach(x0,xd,y0,yd)>r)
            bl = 0;
    if (bl)
        printf("YES");
    else
        printf("NO");
}