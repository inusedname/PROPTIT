#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int stt;
        cin >> stt;
        cout << stt;
        cin.ignore();
        string s;
        getline(cin, s);
        int vt;
        int flag = 0; //12345 5
        for (int i = s.size() - 1; i > 0; i--)
            if (s[i] > s[i - 1])
            {
                flag = 1;
                vt = i - 1;
                break;
            }
        if (flag == 0)
        {
            printf("BIGGEST\n");
            continue;
        }
        for (int j = strlen(s); j >= i; j--)
            if (s[j] > s[i])
            {
                char b = s[i];
                s[i] = s[j];
                s[j] = b;
                break;
            }
        sort(s + i + 1, s + strlen(s));
        printf("%s", s);
        printf("\n");
    }
}