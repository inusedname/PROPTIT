#include <stdio.h>
#include <conio.h>

struct DIEM
{
    int hd;
    int td;
};
struct DIEM xy[2];

void nhap(DIEM xy[])
{
    for (int i = 0; i < 2; i++)
    {
        printf("Nhap hoanh do va tung do cua diem %d: ", i);
        scanf("%d", &xy[i].hd);
        scanf("%d", &xy[i].td);
    }
}
void xuat(DIEM xy[])
{
    for (int i = 0; i < 2; i++)
    {
        printf("Toa do diem thu %d la (%d; %d)", i, xy[i].hd, xy[i].td);
    }
}
main()
{
    int i;
    nhap(xy);
    xuat(xy);
}