#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string cmd;
    int tmp;
    vector<int> s;
    while (1)
    {
        cin >> cmd;
        if (cmd == "init")
            s.clear(), s.resize(0);
        else if (cmd == "push")
        {
            cin >> tmp;
            cin.ignore();
            s.push_back(tmp);
        }
        else if (cmd == "pop" && s.size())
            s.pop_back();
        else if (cmd == "top")
        {
            if (s.size())
                cout << s.back() << endl;
            else
                cout << -1 << endl;
        }
        else if (cmd == "size")
            cout << s.size() << endl;
        else if (cmd == "empty")
            cout << s.empty() << endl;
        else if (cmd == "end")
            break;
    }
}