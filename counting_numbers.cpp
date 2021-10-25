#include<bits/stdc++.h>
using namespace std;
#define lli long long int

lli dp[20][10][2][2];

lli solve(string& number,int n,int x,bool leading_zeros,bool tight)
{
    if(n==0)return 1;
    if(x!=-1 && dp[n][x][leading_zeros][tight]!=-1) return dp[n][x][leading_zeros][tight]; 
    int lb=0;
    int ub = (tight==true)?(number[number.length()-n]-'0'):9;

    lli answer=0;
    for(int dig=lb ; dig<=ub ; dig++)
    {
        if(dig==x && leading_zeros==0) continue;
        answer+= solve(number,n-1,dig, (leading_zeros & (dig==0)),tight & (dig==ub));
    }
    return dp[n][x][leading_zeros][tight]=answer;
    

}


int main()
{
    
    lli a,b;
    cin >> a >> b;
    string A = to_string(a-1);
    string B = to_string(b);
    memset(dp,-1,sizeof(dp));
    lli ans1 = solve(B,B.length(),-1,1,1);
    memset(dp,-1,sizeof(dp));
    lli ans2 = solve(A,A.length(),-1,1,1);
    cout << ans1-ans2 << endl;   
    return 0;
}