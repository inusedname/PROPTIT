#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct diem {
    int x;
    int y;
};

double dodai (diem d1, diem d2)
{
    return sqrt((d1.x - d2.x) * (d1.x - d2.x) + (d1.y - d2.y) * (d1.y - d2.y));
}
int main()
{
    int n;
    cin >> n;
    vector<diem> list(n);
    for (int i = 0; i < n;i++)
    {
        cin >> list[i].x >> list[i].y;
    }
    double max = 10000;
    diem d1, d2;
    for (int i = 0; i < n;i++)
    {
        for (int j = i + 1; j < n;j++)
        {
            double d = dodai(list[i], list[j]);
            if (d < max)
            {    
                max = d;
                d1 = list[i];
                d2 = list[j];
            }
        }
    }
    cout << endl << endl << d1.x << " " << d1.y << endl;
    cout << d2.x << " " << d2.y << endl;
    cout << max;
}