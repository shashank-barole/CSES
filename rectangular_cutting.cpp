/*
https://youtu.be/LdynQjWsO5Q
*/


#include<bits/stdc++.h>
using namespace std;
int a,b;

int solve()
{
    int dp[a+1][b+1];
    memset(dp,0,sizeof dp);
    for(int height=1 ; height<=a ; height++)
    {
        for(int width=1 ; width<=b ; width++)
        {
            if(height==width)dp[height][width]=0;
            else
            {
                int ans=1e9;
                //vertical cuts
                for(int i=1 ; i<width ; i++)
                {
                    ans =min(ans,1+dp[height][width-i]+dp[height][i]);
                }
                //horizontal cuts
                for(int i=1 ; i<height ; i++)
                {
                    ans = min(ans,1+dp[i][width]+dp[height-i][width]);
                }
                dp[height][width]=ans;
            }
        }
    }
    return dp[a][b];
}

int main()
{
    cin >> a >> b;
    cout << solve() << endl;
    return 0;
}