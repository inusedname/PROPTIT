#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int i = s.size() - 1;
    while (s[i] == '0')
        i--;
    s[i] = '0';
    for (int j = i + 1; j < s.size(); j++)
        s[j] = '1';
    cout << s;
}