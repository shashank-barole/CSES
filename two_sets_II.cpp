#include<iostream>
using namespace std;
const int MOD =  1e9 + 7;
long long dp[501][500*501/2 +1];
int main()
{
    int n;
    cin >> n;
    int total = n*(n+1)/2 ;
    if(total&1) cout << 0 << endl;
    else
    {
        total/=2;
        dp[0][0]=1;
        for(int i=1 ; i<n ; i++)
        {
            for(int j=0 ; j<=total ; j++)
            {
                dp[i][j] = dp[i-1][j]%MOD;
                int left = j-i;
                if(left>=0)
                {
                    dp[i][j] = (dp[i][j] + dp[i-1][left]%MOD)%MOD;
                } 
            }
        }
        cout << dp[n-1][total] << endl;
    }

    return 0;
}