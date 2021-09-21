#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin >> n;
    vector<int> dp(n+1);
    dp[0]=0;
    for(int i=1 ; i<=n ; i++)
    {
        int temp = i;
        int min_op = 1e6+10;
        while(temp!=0)
        {
            int digit = temp%10;
            temp/=10;
            if (digit==0) continue;
            min_op = min(min_op,dp[i-digit]+1);
        }
        dp[i]=min_op;
    }
    cout << dp[n] << endl;
    return 0;
}