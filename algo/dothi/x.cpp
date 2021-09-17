int nhap(int a[]);

int xuat(int a[]);

int tinhTong(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + a[i];
    return sum;
}

int sapXepTang(int a[], int n)
{
    // Sử dụng phương pháp đổi chỗ trực tiếp
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i] > a[j])
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
    xuat(a);
}