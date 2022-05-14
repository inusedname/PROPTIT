/* static.c */
#include <stdio.h>
int natural_generator()
{
        int a = 1;
        static int b = -1;
        b += 1;
        return a + b;
}

int main()
{
        printf("%d\n", natural_generator());
        printf("%d\n", natural_generator());
        printf("%d\n", natural_generator());

        return 0;
}