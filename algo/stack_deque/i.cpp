#include <iostream>
#include <stack>
using namespace std;

stack<char> front, back;

int main()
{
    char c;
    while (cin >> c)
    {
        if (c == '<')
        {
            if (!back.empty())
            {
                front.push(back.top());
                back.pop();
            }
        }
        else if (c == '>')
        {
            if (!front.empty())
            {
                back.push(front.top());
                front.pop();
            }
        }
        else if (c == '-')
            if (!back.empty())
                back.pop();
            else
                back.push(c);
    }
    while (!back.empty())
    {
        front.push(back.top());
        back.pop();
    }
    while (!front.empty())
    {
        cout << front.top();
        front.pop();
    }
}