/*
Video explanation  : https://youtu.be/-pXjopzMVrE
*/


#include<bits/stdc++.h>
using namespace std;
int n,x,MOD=1e9+7;


int main()
{
    cin >> n >> x;
    vector<int> coins(n+1);
    int dp[n+1][x+1];
    for(int i=1 ; i<=n ; i++) cin >> coins[i];
    for(int i=1 ; i<=n ; i++)
    {
        for(int sum=0 ; sum<=x ; sum++)
        {
            if(sum==0)
            {
                dp[i][sum]=1;
            } 
            else
            {
                int dont_use = (i==1) ? 0 : dp[i-1][sum];
                int u = coins[i]>sum ? 0 : dp[i][sum - coins[i]];
                dp[i][sum] = (dont_use + u)%MOD;
            }
        }
    }

    cout << dp[n][x] << endl;
    return 0;
}
