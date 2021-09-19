#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[(int) 1e5 + 1];
bool visit[(int) 1e5 + 1];
int p[(int)1e5 + 1];

void dfs(int v,int parent)
{
    visit[v]=true;
    p[v]=parent;
    for(int u: adj[v])
    {
        if(visit[u]==false)
        {
            dfs(u,v);
        }
        else if(u != parent)
        {
            vector<int> path;
            path.push_back(v);
            int curr = v;
            while(p[curr]!=u)
            {
                curr = p[curr];
                path.push_back(curr);
            }
            path.push_back(u);
            path.push_back(v);
            cout << path.size() << endl;
            for(auto x:path) cout << x << " ";
            exit(0);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0 ; i<m ; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i <=n ; i++)
    {
        if(visit[i]==false)
        {
            dfs(i,-1);
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}