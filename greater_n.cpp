#include<bits/stdc++.h>
using namespace std;
#define lli long long int

lli solve(lli& n)
{
    lli len = log10(n)+1;

    if(len==1)
    {
        if(n<9) return n+1;
        return 11;
    }
    lli tmp=0;
    for(lli i=0; i<len ; ++i)
    {
        tmp = tmp*10 +1;
    }
    for(lli j=1 ; j<=9 ; j++)
    {
        if((tmp*j) > n) return (tmp*j) ;
    }

    return tmp*10 +1;

}

int main()
{
    lli t;
    cin >>t;
    while (t--)
    {
        lli n;
        cin >> n;
        cout << solve(n) << endl;
        /* code */
    }
    
    return 0;
}