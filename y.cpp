#include <bits/stdc++.h>
#define endl "\n"
#define pii pair<int, int>
const int oo = 1e9 + 7;
using namespace std;

vector<string> dictionary;
vector<string> newWords = {"cucumber", "melon", "watermelon"};
void read(ifstream &f)
{
    string tmp;
    while (!f.eof())
    {
        f >> tmp;
        dictionary.push_back(tmp);
    }
    for (int i = 0; i < dictionary.size(); i++)
        cout << dictionary[i] << endl;
}
void write(ofstream &f)
{
    for (int i = 0; i < newWords.size(); i++)
    {
        f << endl;
        f << newWords[i];
    }
}
int main()
{
    const char *cstrin = "y.txt";
    ifstream fin(cstrin, ios::in);
    read(fin);
    fin.close();
    const char *cstrout = "y.txt";
    ofstream fout(cstrout, ios::app);
    write(fout);
    fout.close();
}
