#include <iostream>
#include <vector>
using namespace std;

int main()
{
    char c;
    vector<char> alpha;
    vector<char> num;
    while (cin >> c)
    {
        if (isalpha(c))
            alpha.push_back(c);
        else
            num.push_back(c);
    }
    while (alpha.size())
    {
        cout << alpha.back();
        alpha.pop_back();
    }
    cout << "\n";
    for (int i = 0; i < num.size(); i++)
        cout << num[i];
}