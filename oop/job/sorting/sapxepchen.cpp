#include <iostream>
using namespace std;
int main()
{
    int a[100] = {3, 5, 4, 6, 1};
    int n = 5;
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && a[i] < a[j - 1])
            j--;
        int tmp = a[i];
        for (int k = i; k > j; k--)
            a[k] = a[k - 1];
        a[j] = tmp;
    }
    for (int i = 0; i < n; i++)
        cout << a[i];
    // Độ phức tạp thời gian O(n^2)
    // Độ phức tạp không gian O(1)
}