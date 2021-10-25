#include<bits/stdc++.h>
using namespace std;
#define lli long long int


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
        int a,b;
        cin >> a >> b;
        cout << bin_exp(a,b,(int)1e9 + 7) << endl;
    }
    return 0;
}