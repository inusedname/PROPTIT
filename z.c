#include <stdio.h>
#include <math.h>
int nto(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    int a[n];
    printf("Nhap mang a[n]: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int m, k;
    printf("Nhap m va k: ");
    scanf("%d%d", &m, &k);
    int sumofMod = 0;
    int sumofPrime = 0;
    int sumofSquare = 0;
    printf("Xuat mang: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        if (a[i] % m == 0 && a[i] % k != 0)
            sumofMod++;
        if (nto(a[i]))
            sumofPrime++;
        if (sqrt(a[i]) == (float)sqrt(a[i]))
            sumofSquare++;
    }
    printf("\nChia het cho m ko chia het cho k: %d\n", sumofMod);
    printf("So nguyen to: %d\n", sumofPrime);
    printf("So chinh phuong: %d\n", sumofSquare);
    return 0;
}