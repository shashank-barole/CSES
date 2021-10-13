#include<bits/stdc++.h>
using namespace std;

// https://youtu.be/MJn3ogwsUbo
struct project
{
    int st,end,rwd;
};

bool cmp(project& p1,project& p2)
{
    return p1.end < p2.end;
}

int find_best_j(vector<int> & end_pts,int st)
{
    auto it = lower_bound(end_pts.begin(),end_pts.end(),st);
    if(it == end_pts.begin())
    {
        return 0;
    }
    else
    {
        it--;
        return 1 + distance(end_pts.begin(),it);
    }
}

long long int solve(vector<project>& v,int n)
{
    long long int dp[n+1];
    dp[0]=0;
    vector<int> end_pts;
    for(int i=1 ; i<=n ; i++)
    {
        end_pts.push_back(v[i].end);
    }
    for(int i=1 ; i<=n ; i++)
    {
        long long int op1 = dp[i-1];
        long long int op2 = v[i].rwd;
        int j = find_best_j(end_pts,v[i].st);
        op2+=dp[j];
        dp[i] = max(op1,op2);
    }
    return dp[n];
}


int main()
{
    int n;
    cin >> n;
    vector<project> v(n+1);
    for(int i=1 ; i<=n ; i++)
    {
        cin >> v[i].st >> v[i].end >> v[i].rwd;
    }

    sort(v.begin()+1,v.end(),cmp);
    cout << solve(v,n) << endl;
    return 0;
}