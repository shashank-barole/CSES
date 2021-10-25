#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const int MOD = (int)1e9 + 7;


lli bin_exp(int a,int b,int m)
{
    lli ans=1;
    while(b)
    {
        if(b&1)
        {
            ans = (ans * 1LL * a)%m;
            b-=1;
        }
        else
        {
            a = (a* 1LL * a)%m;
            b/=2;
        }
    }
    return ans%m ;
}

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        cout << bin_exp(a,(bin_exp(b,c,MOD-1)),MOD) << endl;
    }
    return 0;
}