#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int tong = 0;
        for (int i = 1; i < n;i++)
        {
            if (n%i==0)
                tong = tong + i;
        }
        if (tong == n)
            printf("So hoan hao");
        else
            printf("So khong hoan hao");
        printf("\n");
    };
}
//nhập chuỗi -> nếu mà scanf("" -> ct lỗi) cta dùng cái getchar để tránh bị lỗi