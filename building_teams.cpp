#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[(int)1e5 + 1];
int color[(int) 1e5 +1];
bool visit[(int) 1e5 +1];
bool dfs(int v,int c)
{
    visit[v]=true;
    color[v]=c;
    for(int u : adj[v])
    {
        if(visit[u]==false)
        {
            if(dfs(u,c^1)==false) return false;
        }
        else if(color[v] == color[u]) return false;
    }
    return true;
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
    bool flag=false;
    for(int i=1 ; i<=n ; i++)
    {
        if(visit[i]==false)
        {
            flag=dfs(i,1);
            if(flag==false)break;
        }
    }
    if(flag==false) cout << "IMPOSSIBLE" << endl;
    else
    {
        for(int i=1 ; i<=n ; i++)
        {
            cout << color[i]+1 << " " ;
        }
    }
    return 0;

}