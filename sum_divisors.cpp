#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const int MOD = 1e9 + 7;

lli bin_exp(lli a,lli b)
{
    lli ans=1;
    while(b)
    {
        if(b&1)
        {
            ans = (ans * 1LL * a)%MOD;
            b-=1;
        }
        else
        {
            a = (a* 1LL * a)%MOD;
            b/=2;
        }
    }
    return ans%MOD ;
}


void print_vec(vector<int>& nums)
{
    for(auto i:nums) cout << i << endl;
}


int main()
{
    lli n;
    cin >> n;
    lli answer=0;
    for(lli i=1,j ; i<=n ; i=j)
    {
        lli q = n/i;
        j = n/q + 1;
        lli range_sum_j_1 = ((((j%MOD)*((j-1)%MOD))%MOD)*bin_exp(2,MOD-2))%MOD;
        lli range_sum_i_1 = ((((i%MOD)*((i-1)%MOD))%MOD)*bin_exp(2,MOD-2))%MOD;
        lli rwq = (range_sum_j_1 - range_sum_i_1 + MOD)%MOD;
        answer = (answer + (q%MOD)*rwq)%MOD;
    }
    cout << answer << endl;
    return 0;
}