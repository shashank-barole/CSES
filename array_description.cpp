#include<bits/stdc++.h>
using namespace std;
int n,m,MOD=1e9+7;
int arr[(int)1e5+1];

int solve()
{
    int dp[n+1][m+1];
    memset(dp,0,sizeof dp);
    for(int i=1 ; i<=n ; i++)
    {
        for(int x=1 ; x<=m ; x++)
        {
            if(i==1)
            {
                if(arr[i]==0 || arr[i]==x){
                    dp[i][x] = 1;
                }
                else
                {
                    dp[i][x]=0;
                }
            }
            else
            {
                if(arr[i]==0 || arr[i]==x){
                    dp[i][x] = ((dp[i-1][x-1]%MOD + dp[i-1][x])%MOD + dp[i-1][x+1])%MOD;
                }
                else
                {
                    dp[i][x]=0;
                }
            }
        }
    }
    int ans=0;
    for(int x=1 ; x<=m ; x++)
    {
        ans = (ans + dp[n][x])%MOD;
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
    }
    cout << solve() << endl;

    return 0;
}