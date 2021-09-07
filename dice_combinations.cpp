#include<iostream>
#include<vector>
using namespace std;
int n;
vector<long long> dp(1000000,0);
const int MOD = 1e9 + 7;

int main()
{
    cin >> n;
    dp[0]=1;

    for(long long i=1 ; i<=n ; i++)
    {
            if( i>=1) dp[i]=(dp[i]+dp[i-1])%MOD;
            if( i>=2) dp[i]=(dp[i]+dp[i-2])%MOD;
            if( i>=3) dp[i]=(dp[i]+dp[i-3])%MOD;
            if( i>=4) dp[i]=(dp[i]+dp[i-4])%MOD;
            if( i>=5) dp[i]=(dp[i]+dp[i-5])%MOD;
            if( i>=6) dp[i]=(dp[i]+dp[i-6])%MOD;
    }
    cout << dp[n] << endl;
    
    return 0;
}