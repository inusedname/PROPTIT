#include <iostream>
using namespace std;

void nhap(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int tinhTong(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + a[i];
    return sum;
}

void sapXepTang(int a[], int n)
{
    // Sử dụng phương pháp đổi chỗ trực tiếp
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
    xuat(a, n);
}

void insertNum(int a[], int n, int val, int pos)
{
    for (int i = n - 1; i >= pos; i--)
        a[i + 1] = a[i];
    a[pos] = val;
    xuat(a, n + 1);
}
int main()
{
    int n;
    int a[100];
    cin >> n;
    nhap(a, n);
    int val, k;
    cin >> val >> k;
    insertNum(a, n, val, k);
}