#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> nums(5000,0);
long long dp[5001][5001];

int main()
{
    cin >> n;
    for(int i=0 ; i<n  ; i++) cin >> nums[i];
    long long dp[5001][5001];
    for(int len=1 ; len<=n ; len++)
    {
        for(int i=0 ; i<= n-len ; i++)
        {
            int j=i+len-1;
            long long a = (i+2 <= j)?dp[i+2][j]:0;
            long long b = (i+1 <= j-1)?dp[i+1][j-1]:0;
            long long c = (i<= j-2)?dp[i][j-2]:0;
            dp[i][j] = max(nums[i] + min(a,b) , nums[j] + min(b,c));
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}