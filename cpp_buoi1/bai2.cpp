#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s; //lap trinh bang ngon ngu c
    getline(cin, s);
    for (int i = s.length() - 1; i >= 0;i--)
    {
        int dem = 0;
        while (s[i] != ' ' && i >= 0)
        {
            dem++;
            i--;
        }
        for (int j = i + 1; j < i + 1 + dem;j++)
        {
            cout << s[j];
        }
        cout << " ";
    }
}