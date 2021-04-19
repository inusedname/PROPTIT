#include <stdio.h>

int main()
{
    int n; //5
    scanf("%d", &n);
    int a[n];                       // a[5]
    for (int i = 0; i < n + 2; i++) //1 2 3 4 5 6
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
//a[n]
//a[0] -> a[n-1]=a[4]
// C++ nó sẽ dư ra 2 phần tử thừa ở cuối
// n=5 a[5] a[0]->a[4]
// a[5] a[6] ->