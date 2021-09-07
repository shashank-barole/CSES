#include<iostream>
using namespace std;
int m,n,answer=0;
int visit[1000][1000];
char map[1000][1000];

bool is_valid(int r, int c)
{
    if ( r<0 || c<0 || r>=m || c>=n || map[r][c]=='#' || visit[r][c])
    {
        return false;
    }
    return true;
}

void DFS(int r,int c)
{
    if(is_valid(r,c))
    {
        visit[r][c]=1;
        DFS(r,c+1);
        DFS(r,c-1);
        DFS(r+1,c);
        DFS(r-1,c);
    }
}

int main()
{
    cin >> m >> n;
    for(int i=0 ; i<m ; i++)
    {
        for(int j=0; j<n ; j++)
        {
            cin >> map[i][j];
            visit[i][j]=0;
        }
    }

    for(int i=0 ; i<m ; i++)
    {
        for(int j=0; j<n ; j++)
        {
            if(map[i][j] == '.' && visit[i][j]==0)
            {
                DFS(i,j);
                answer++;
            }
        }
    }

    cout << answer << endl;


    return 0;
}