#include <iostream>

int a[100];
int b[100]; //temporary

void Merge(int i, int k, int j)
{
    int left = i, right = k + 1;
    int t = i;
    while (left <= k && right <= j)
    {
        if (a[left] < a[right])
            b[t++] = a[left++];
        else
            b[t++] = a[right++];
    }
    if (left > k)
    {
        for (int r = right; r <= j; r++)
            b[t++] = a[r];
    }
    else
    {
        for (int r = left; r <= k; r++)
            b[t++] = a[r];
    }
    for (int r = i; r <= j; r++)
    {
        a[r] = b[r];
    }
}
void mergeSort(int i, int j)
{
    if (i < j)
    {
        int m = (i + j) / 2;
        mergeSort(i, m);
        mergeSort(m + 1, j);
        Merge(i, m, j);
    }
}
int main()
{
    a[0] = 4;
    a[1] = 9;
    a[2] = 3;
    a[3] = 5;
    a[4] = 7;
    a[5] = 2;
    mergeSort(0, 5);
    for (int i = 0; i < 6; i++)
        std::cout << a[i] << " ";
}
//ĐỘ PHỨC TẠP THỜI GIAN: O(N^2)
//ĐỘ PHỨC TẠP KHÔNG GIAN: O(N)