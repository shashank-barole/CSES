#include<bits/stdc++.h>
using namespace std;

// https://codeforces.com/blog/entry/70018

int main()
{
    int n;
    cin >> n;
    vector<int> dp;
    for(int i=0 ; i<n ; i++)
    {
        int x;
        cin >> x;
        auto it = lower_bound(dp.begin(),dp.end(),x);
        if(it == dp.end()) dp.push_back(x);
        else *it = x;
    }

    cout << dp.size() << endl;
    return 0;
}