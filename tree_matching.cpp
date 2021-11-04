/*

Great Explanation : https://youtu.be/RuNAYVTn9qM
*/



#include<bits/stdc++.h>
using namespace std;
vector<int> adj[(int)2e6 + 1];
int dp[(int)2e6 + 1][2];

void solve(int src,int par)
{
    vector<int> prefix,suffix;
    int leaf=1;
    dp[src][0]=dp[src][1]=0;
    for(int child : adj[src])
    {
        if(child!=par)
        {
            leaf=0;
            solve(child,src);
        }
    }
    if(leaf==1)return;
    for(int child : adj[src])
    {
        if(child!=par)
        {
            prefix.push_back(max(dp[child][0],dp[child][1]));
            suffix.push_back(max(dp[child][0],dp[child][1]));
        }
    }
    for(int i=1 ; i<(int)prefix.size() ; ++i)
    {
        prefix[i]+=prefix[i-1];
    }
    for(int i=(int)suffix.size()-2 ; i>=0 ; --i)
    {
        suffix[i]+=suffix[i+1];
    }
    dp[src][0]=suffix[0];
    int c_n0=0;
    for(int child : adj[src])
    {
        if(child == par) continue;
        int left_children = (c_n0==0)?0: prefix[c_n0-1];
        int right_children = (c_n0==((int)suffix.size()-1))?0:suffix[c_n0+1];
        dp[src][1] = max(dp[src][1],1+left_children + right_children + dp[child][0]);
        c_n0++;
    }
}
int main()
{
    int n;
    cin >> n;
    int a,b;
    for(int i=0 ; i<n-1 ; ++i)
    {
        cin >> a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(1,0);
    cout << max(dp[1][0],dp[1][1]) << endl;
    return 0;
}