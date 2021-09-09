#include <iostream>
#include <stack>
using namespace std;
stack<char> toanTu;
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
        if (toanTu.empty() || toanTu.top() == '(')
            toanTu.push(c);
        else if ((c == '*' || c == '/') && (toanTu.top() == '+' || toanTu.top() == '-'))
            toanTu.push(c);
        else
        {
            while (!toanTu.empty() && toanTu.top() != '(')
            {
                cout << toanTu.top();
                toanTu.pop();
            }
            toanTu.push(c);
        }
    }
    while (!toanTu.empty())
    {
        cout << toanTu.top();
        toanTu.pop();
    }
}