#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<string> st;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (isalpha(s[i]))
            st.push(string(1, s[i]));
        else
        {
            string x = st.top();
            st.pop();
            string y = st.top();
            st.pop();
            st.push(s[i] + y + x);
        }
    cout << st.top();
}