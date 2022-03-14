#if 0
#include"../stdc++.h"
#endif
#if 1
#include<bits/stdc++.h>
#endif
using namespace std;
int coins[101];
const int MOD = (int)1e9 + 7;
int dp[(int)1e6+10];
int main()
{
    memset(coins,0,sizeof(coins));
    memset(dp,0,sizeof(dp));
    int n,x;
    cin >> n >> x;
    for(int i=0 ; i<n ;++i) cin >> coins[i];
    dp[0]=1;
    for(int i=1 ; i<=x ; ++i)
    {
        for(int c=0 ; c<n ; ++c)
        {
            if(coins[c]<=i) (dp[i]+=dp[i-coins[c]]) %=MOD;
        }
    }
    cout << dp[x] << "\n";
    return 0;
}