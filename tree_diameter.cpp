#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200000 + 1];
int depth[200000+1];

void print_vec(vector<int>& a)
{
    for(auto i:a)
    {
        cout << i << endl;
    }
}

void dfs(int node,int par=-1)
{
    for(int child : adj[node])
    {
        if(child == par) continue;
        depth[child] = depth[node]+1;
        dfs(child,node);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0 ; i<(n-1) ; ++i)
    {
        int a,b;
        cin >> a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    int max_depth = -1;
    int max_d_node;
    for(int i=1 ; i<=n ; ++i)
    {
        if(max_depth < depth[i])
        {
            max_depth = depth[i];
            max_d_node = i;
        }
        depth[i]=0;
    }
    dfs(max_d_node);
    max_depth=-1;
    for(int i=1 ; i<=n ; ++i)
    {
        if(max_depth < depth[i])
        {
            max_depth = depth[i];
            max_d_node = i;
        }
        depth[i]=0;
    }
    cout << max_depth << endl;
    return 0;
}