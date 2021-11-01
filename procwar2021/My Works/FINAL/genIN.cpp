#include "testlib.h"
#include <bits/stdc++.h>
#define endl "\n"
const float MAX = 50.00;
using namespace std;

int n = 2, tmp, gen;
int firstgen, yesno, howSon;
int t, u, v;
vector<pair<int, int>> r;
void dequi(int dad, int son, int layer)
{
    if (layer == 5)
        return;
    for (int i = 0; i < son; i++)
    {
        int thisdad = n;
        r.push_back({dad, n}), n++;
        yesno = rnd.next(1, 1000); //Quyết định có con hay không
        if (yesno % 2)
        {
            howSon = rnd.next(1, 5);
            dequi(thisdad, howSon, layer + 1);
        }
    }
}
void GenTest()
{
    r.clear(), n = 2;
    firstgen = rnd.next(1, 10); //thế hệ đầu tiên bắt buộc phải có con
    dequi(1, firstgen, 2);
    n--;
    cout << n << " " << r.size() << endl;
    for (int i = 0; i < r.size(); i++)
        cout << r[i].first << " " << r[i].second << endl;
    t = rnd.next(1, 10);
    cout << t << endl;
    for (int i = 0; i < t; i++)
    {
        u = rnd.next(1, n);
        v = rnd.next(1, n);
        while (u == v)
            v = rnd.next(1, n);
        cout << u << " " << v << endl;
    }
}

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int numT = 10;
    for (int i = 1; i <= numT; i++)
    {
        const char *dir = ("input/" + to_string(i) + ".in").c_str();
        FILE *f = freopen(dir, "w", stdout);
        GenTest();
        fclose(f);
    }
}