#include <stdio.h>
#define ll long long 

int main()
{
	int mod = 1e9 + 7;
    int n;
    scanf("%d",&n);
    // tm 2 ^ (n-1)
    ll res = 1;
    for (int i = 1; i < n;i++)
    {
    	res = (res * 2)%mod;
    }
    printf("%d",res);
}
