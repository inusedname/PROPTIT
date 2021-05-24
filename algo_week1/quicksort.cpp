#include <iostream>
using namespace std;

int a[100005];
int n;
int partition(int left, int right)
{
    int pivot = right;
    int addpivot = right;
    right--;
    while (1)
    {
        while (left <= right && a[left] < a[pivot])
            left++;
        while (left <= right && a[right] > a[pivot])
            right--;
        if (left >= right)
            break;
        swap(a[left], a[right]);
        left++;
        right--;
    }
    swap(a[left], a[addpivot]);
    return left;
}
void quicksort(int left, int right)
{
    if (left < right)
    {
        int pi = partition(left, right);
        quicksort(left, pi - 1);
        quicksort(pi + 1, right);
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quicksort(0, n - 1);
    cout << a[k - 1];
}