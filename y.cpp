#include <iostream>
#define endl "\n"
using namespace std;
int main()
{
    // tính tổng từ 1 + 2 + 3 + 4 + 5 +...+ n
    int n;
    printf("Vui long nhap vao so n: "); // In ra
    scanf("%d", &n);                    // Nhập vào n
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum = sum + i;
    printf("%d", sum);
}