#include<bits/stdc++.h>
using namespace std;
int m,n;
char lab[1001][1001];
char direction[1001][1001];
bool visit[1001][1001];
vector<char> path;

bool isValid(int r,int c)
{
    return (r>=0 && r<m && c>=0 && c<n && visit[r][c]==false && lab[r][c]!='#');
}

bool bfs(int r,int c)
{
    queue< pair<int,int> > q;
    q.push({r,c});
    visit[r][c]=true;
    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        if(lab[row][col] == 'B')
        {   while (!(row==r && col==c))
            {
                path.push_back(direction[row][col]);
                if(path.back()=='L') col++;
                else if(path.back()=='R') col--;
                else if(path.back()=='U') row++;
                else if(path.back()=='D') row--;
            }
            return true;
        }
        if(isValid(row,col-1))
        {
            q.push({row,col-1});
            visit[row][col-1]=true;
            direction[row][col-1]='L';
        }
        if(isValid(row,col+1))
        {
            q.push({row,col+1});
            visit[row][col+1]=true;
            direction[row][col+1]='R';
        }
        if(isValid(row-1,col))
        {
            q.push({row-1,col});
            visit[row-1][col]=true;
            direction[row-1][col]='U';
        }
        if(isValid(row+1,col))
        {
            q.push({row+1,col});
            visit[row+1][col]=true;
            direction[row+1][col]='D';
        }
    }
    return false;    
}


int main()
{
    cin >> m >> n;
    int r=-1,c=-1;
    for (int i=0 ; i<m ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            cin >> lab[i][j];
            if (lab[i][j]=='A') r=i,c=j;
        }
    }
    bool result = bfs(r,c);
    if(result == true)
    {
        cout << "YES" << endl << path.size() << endl;
        while(path.size()>0) cout << path.back(),path.pop_back();
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}