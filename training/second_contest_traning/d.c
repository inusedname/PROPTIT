#include <stdio.h>
#include <math.h>
int ktnt (int sum)
{
    int j = 2;
    for (j; j <= sqrt(sum);j++)
        if (sum%j==0)
            return 0;
    if (sum==1)
        return 0;
    return 1;
}
int main()
{
    int l, r, i;
    int sum;
    int dem=0;
    scanf("%d%d", &l, &r);
    for (i = l + 1; i <= r;i++)
    {
        int temp = i;
        sum = 0;
        while(temp)
        {
            sum = sum + (temp % 10);
            temp = temp / 10;
        }
        if (ktnt(sum))
        {
            dem++;
        }
    }
    printf("%d",dem);
}