#include<iostream>
using namespace std;
#define ll long long
int N;
ll nums[20];


int main()
{
    cin >> N;
    ll sum = 0;
    ll ans = INT32_MIN;
    for(int i=0 ; i<N ; i++)
    {
        cin >> nums[i];
        sum+=nums[i];
    }

    for(int i=0 ; i< 1<<N ; i++)
    {
        ll curr = 0;
        for (int j=0 ; j<N ; j++)
        {
            if( i>>j&1) curr+=nums[j];
        }
        if (curr <= sum/2) ans = curr>ans ? curr : ans;
        
    }
    cout << sum - 2*ans << endl;
    return 0;
}