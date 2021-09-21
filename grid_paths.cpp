#include<bits/stdc++.h>
using namespace std;
int n,MOD=1e9+7;

int main()
{
    cin >> n;
    int dp[n+1][n+1];
    bool matrix[n+1][n+1];
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; ++j)
        {
            char ch;
            cin >> ch;
            if(ch=='*')matrix[i][j]=0;
            else matrix[i][j]=1;
        }
    }

    for(int i=n ; i>=1 ; i--)
    {
        for(int j=n ; j>=1 ; j--)
        {
            if(i==n && j==n) dp[i][j]=1;
            else
            {
                int right = (j==n)?0 : dp[i][j+1];
                int down = (i==n)?0 : dp[i+1][j];
                dp[i][j] = (right+down)%MOD;
                if(matrix[i][j]==0) dp[i][j]=0;
            }
        }
    }

    if(matrix[n][n]==0) cout << 0 << endl;
    else
    cout << dp[1][1] << endl;

    return 0;
}