#include<bits/stdc++.h>
using namespace std;
long long dp[(int)1e6 + 1],coins[101];
int n,x;

int main()
{
    cin >> n >> x;
    for(int i=0 ; i<n ; i++)
    {
        cin >> coins[i];
    }
    dp[0]=0;
    for(int i=1 ; i<=x ; i++)
    {
        dp[i]=(int)1e9;
        for(int j=0 ; j<n ; j++)
        {
            if(coins[j]<=i) dp[i] = min(dp[i],dp[i-coins[j]]+1);
        }
    }
    if(dp[x]==1e9) cout << -1 << endl;
    else
    cout << dp[x] << endl;
    return 0;
}