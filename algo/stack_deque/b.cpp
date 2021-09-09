#include <iostream>
#include <stack>
using namespace std;
stack<char> toanTu;
int check(char c)
{
    if (c == '(')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    return 2;
}
int main()
{
    char c;
    while (cin >> c)
    {
        if (c >= 'A' && c <= 'Z')
        {
            cout << c;
            continue;
        }
        if (c == ')')
        {
            while (toanTu.top() != '(')
            {
                cout << toanTu.top();
                toanTu.pop();
            }
            toanTu.pop();
            continue;
        }
        if (c == '(')
        {
            toanTu.push('(');
            continue;
        }
        while (!toanTu.empty() && check(c) <= check(toanTu.top()))
        {
            cout << toanTu.top();
            toanTu.pop();
        }
        toanTu.push(c);
    }
    while (!toanTu.empty())
    {
        cout << toanTu.top();
        toanTu.pop();
    }
}
