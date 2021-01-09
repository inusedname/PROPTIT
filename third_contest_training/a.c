#include <stdio.h> //use GCC+17 9.2.0
int main()
{
    int T;
    scanf("%d",&T);
    while (T)
    {
        int n, i;
        scanf("%d",&n);
        int check=n;
        int temp, cons;
        scanf("%d",&cons);
        int fir=cons, sec=-99999;
        for (i=1;i<n;i++)
        {
            scanf("%d",&temp);
            if (temp==cons) check--; //check=1 -> out
            if (check==1)
            {
                printf ("0");
                return 0;
            }
            if (temp>fir)
            {
                sec = fir;
                fir = temp;
            }
            if (temp>sec&&temp!=fir)
            {
                sec = temp;
            }
        }
        printf ("%d %d",sec,fir);
        T--;
        printf ("\n");
    }
}
