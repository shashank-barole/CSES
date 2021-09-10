#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a,b,ans=0,current=0;
    cin >> n;
    vector< pair<int,int> > v;
    for(int i=0 ; i<n ; i++)
    {
        cin >> a >> b;
        v.push_back({a,-1});
        v.push_back({b,1});
    }

    
    sort(v.begin(),v.end());

    for(auto i= v.begin() ; i< v.end() ; i++)
    {
        ans = max(ans,current);
        current+= -1*(i->second);
    }
    cout << ans << endl;


    return 0;
}