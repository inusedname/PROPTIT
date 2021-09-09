#include <iostream>
#include <stack>
using namespace std;

stack<char> st;

int check(char c)
{
    if (c == '(')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
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
        if (c == '(')
        {
            st.push(c);
            continue;
        }
        if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                cout << st.top();
                st.pop();
            }
            st.pop();
            continue;
        }
        while (!st.empty() && check(c) <= check(st.top()))
        {
            cout << st.top();
            st.pop();
        }
        st.push(c);
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}