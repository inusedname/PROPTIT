#include <iostream>
using namespace std;
int main()
{
    int a[100];
    int n = 100;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
    // Độ phức tạp thời gian O(n^2)
    // Độ phức tạp không gian O(1)
}