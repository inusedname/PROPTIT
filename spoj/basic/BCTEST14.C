#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a, b, v;
    scanf("%lf %lf %lf", &a, &b, &v);
    printf("%.0lf", ceil(((v - a) / (a - b)) + 1));
}