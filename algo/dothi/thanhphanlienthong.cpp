#include <iostream>
#define ll long long
#define endl "\n"
using namespace std;

int a[50][50], n, chuaxet[50];
void nhap()
{
    // Nhập vào ma trận
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        chuaxet[i] = 1;
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
}

void dfsLT(int u) //tìm DFS
{
    cout << u << " ", chuaxet[u] = 0;
    for (int i = 0; i < n; i++)
    {
        //Ptu chưa đc xét và xuất hiện mối quan hệ với ptu khác
        if (chuaxet[i] && a[u][i] == 1)
            dfsLT(i);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    nhap();
    int soLT = 0;
    for (int u = 0; u < n; u++)
    {
        if (chuaxet[u])
        {
            soLT++;
            dfsLT(u);
            cout << endl;
        }
    }
}