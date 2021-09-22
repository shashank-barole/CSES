#include<bits/stdc++.h>
using namespace std;

int dp[5001][5001];

int solve(int i,int j,string& s1, string& s2)
{
    if(i==s1.length() || j==s2.length())
    {
        return max(s2.length()-j , s1.length()-i);
    }

    if(dp[i][j]!=-1) return dp[i][j];
    int ans;
    if(s1[i]==s2[j])
    {
        ans = solve(i+1,j+1,s1,s2);
    }
    else
    {
        int del = 1 + solve(i+1,j,s1,s2);
        int rep = 1 + solve(i+1,j+1,s1,s2);
        int ins = 1 + solve(i,j+1,s1,s2);
        ans =  min(del,min(rep,ins));
    }
    dp[i][j]=ans;
    return dp[i][j];
}

int main()
{
    memset(dp,-1,sizeof dp);
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    cout << solve(0,0,s1,s2) << endl;

    return 0;
}