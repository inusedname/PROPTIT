#include <iostream>
using namespace std;

int main()
{
    int a[100];
    int n;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
    // Độ phức tạp thời gian O(n^2)
    // Độ phức tạp không gian O(1)
}