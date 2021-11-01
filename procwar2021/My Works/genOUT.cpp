// Log: Bỏ "\n" cuối test
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
int n, m, t;
vector<pair<int, int>> INPUT;
vector<pair<int, int>> TEST;
void input(ifstream &f)
{
    f >> n >> m;
    INPUT.resize(m);
    for (int i = 0; i < m; i++)
        f >> INPUT[i].first >> INPUT[i].second;
    f >> t;
    TEST.resize(t);
    for (int i = 0; i < t; i++)
        f >> TEST[i].first >> TEST[i].second;
}
void say(int x, int y, bool flag, ofstream &f)
{
    int u = abs(x - y);
    switch (u)
    {
    case 3:
        f << "great-grandparent";
        break;
    case 2:
        f << "grandparent";
        break;
    case 1:
        f << "parent";
        break;
    default:
        if (flag)
            f << "sibling";
        else
            f << "cousin";
        break;
    }
    if (u && !flag)
        f << "'s sibling";
}
void solve(ofstream &f)
{
    int u, v;
    int a[n + 5] = {0};
    for (int i = 0; i < m; i++)
    {
        u = INPUT[i].first, v = INPUT[i].second;
        a[v] = u;
    }
    for (int i = 0; i < t; i++)
    {
        u = TEST[i].first, v = TEST[i].second;
        int check1(0), check2(0);
        int tmp = u;
        while (a[tmp])
        {
            check1++;
            tmp = a[tmp];
        }
        tmp = v;
        while (a[tmp])
        {
            check2++;
            tmp = a[tmp];
        }
        //kiểm tra có rẽ nhánh không?
        bool flag = 0;
        if (a[u] == a[v])
            flag = 1;
        else
        {
            if (u < v)
                swap(u, v);
            tmp = u;
            while (a[tmp] && a[tmp] != v)
                tmp = a[tmp];
            if (a[tmp] == v)
                flag = 1;
        }
        say(check1, check2, flag, f);
        if (i != t - 1)
            f << endl;
    }
}

int main()
{
    int numTest = 10;
    for (int i = 1; i <= numTest; i++)
    {
        const char *cstrin = ("input/" + to_string(i) + ".in").c_str();
        ifstream fin(cstrin, ios::in);
        input(fin);
        fin.close();
        const char *cstrout = ("output/" + to_string(i) + ".out").c_str();
        ofstream fout(cstrout, ios::out);
        solve(fout);
        fout.close();
    }
}
