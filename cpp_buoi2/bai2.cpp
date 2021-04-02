#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct number
{
    int num;
    int freq = 0;
    int sum()
    {
        return num * freq;
    }
};

bool sapxepVal(number x1, number x2)
{
    if (x1.freq == x2.freq)
        return x1.num < x2.num;
    return x1.freq > x2.freq;
}
int main()
{
    int n;
    cin >> n;
    vector<number> list(0);
    int tmp;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        cin >> tmp;
        for (int j = 0; j < list.size(); j++)
        {
            if (tmp == list[j].num)
            {
                list[j].freq++;
                flag = 1;
            }
        }
        if (!flag)
        {
            dem++;
            list.resize(dem);
            list[dem - 1].num = tmp;
            list[dem - 1].freq = 1;
        }
    }
    sort(list.begin(), list.end(), sapxepVal);
    for (int i = 0; i < list.size(); i++)
    {
        for (int j = 0; j < list[i].freq; j++)
            cout << list[i].num << " ";
    }
}