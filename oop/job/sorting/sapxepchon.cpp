#include <iostream>

using namespace std;

int main()
{
    int a[100], n;
    for (int i = 0; i < n - 1; i++)
    {
        int posMin = i;
        for (int j = i + 1; j < n; j++)
            if (a[posMin] > a[j])
                posMin = j;
        swap(a[i], a[posMin]);
    }
    // ĐỘ PHỨC TẠP THỜI GIAN: O(N^2)
    // ĐỘ PHỨC TẠP KHÔNG GIAN: O(N)
}