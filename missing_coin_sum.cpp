/*
Video Explanation : https://youtu.be/KrT4kAgfLVo
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i=0 ; i<n ; i++)
    {
        cin >> coins[i] ;
    }
    sort(coins.begin(),coins.end());
    long long small=1;
    for(int i=0 ; i<n && small >= coins[i] ; i++)
    {
        small+=coins[i];
    }

    cout << small << endl;
    return 0;
}