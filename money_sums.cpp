// https://youtu.be/PXdOyrbNr78

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    int sum=0;
    vector<int> values(n);
    for(int i=0 ; i<n ; i++)
    {
        cin >> values[i];
        sum+=values[i];
    }
    vector<int> reachable(sum+1,0);
    reachable[0]=1;
    for(int i=0 ; i<n ; i++)
    {
        for(int value=sum ; value>=values[i] ; value--)
        {
            reachable[value] |= reachable[value - values[i]];
        }
    }
    int cnt=0;
    for(int i=1 ; i<=sum ; i++)
    {
        if(reachable[i]) cnt++;
    }
    cout << cnt << endl;
    for(int i=1 ; i<=sum ; i++)
    {
        if(reachable[i]) cout << i << " ";
    }

    return 0;
}
