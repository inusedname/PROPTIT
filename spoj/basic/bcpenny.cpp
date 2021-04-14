#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        string s, ss;
        int f[8] = {0};
        int k;
        scanf("%d", &k);
        cin.ignore();
        getline(cin, s);
        for (int i = 0; i < 38; i++)
        {
            ss = s.substr(i, 3);
            if (ss == "TTT")
                f[0]++;
            else if (ss == "TTH")
                f[1]++;
            else if (ss == "THT")
                f[2]++;
            else if (ss == "THH")
                f[3]++;
            else if (ss == "HTT")
                f[4]++;
            else if (ss == "HTH")
                f[5]++;
            else if (ss == "HHT")
                f[6]++;
            else if (ss == "HHH")
                f[7]++;
        }
        printf("%d ", k);
        for (int i = 0; i < 8; i++)
            printf("%d ", f[i]);
        printf("\n");
    }
}