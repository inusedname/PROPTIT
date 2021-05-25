#include <stdio.h>

    void IN(int n, int hv[])
    {
        for (int i = 1; i <= n; i++)
            printf("%d", hv[i]);
        printf(" ");
    }
    void swap(int *a, int *b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    int main()
    {
        int n, i;
        int index;
        int min;
        scanf("%d", &n);
        int hv[100];
        for (int i = 1; i <= n; i++)
            hv[i] = i;
        IN(n, hv);
        while (1)
        {
            for (i = n - 1; i > 0; i--)
            {
                if (i == 0)
                    break;
                if (hv[i] < hv[i + 1])
                    break;
            }
            if (i == 0)
                break;
            min = hv[i];
            for (int j = n; j > i; j--)
                if (hv[j] > hv[i])
                {
                    swap(&hv[i], &hv[j]);
                    break;
                }
            int l = i + 1, r = n;
            while (l < r)
            {
                swap(&hv[l], &hv[r]);
                l++, r--;
            }
            IN(n, hv);
        }
    }