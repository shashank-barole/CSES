#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin  >> n >> m;
    multiset<int> prices;
    int p;
    for(int i=0 ; i<n ; i++) cin >> p, prices.insert(p);
    vector<int> max_payable(m,0);
    for(int i=0 ; i<m ; i++) cin >> max_payable[i];
    for(int i=0 ; i<m ; ++i)
    {
        auto it = prices.upper_bound(max_payable[i]);
        if(it == prices.begin())
        {
            cout << -1 << "\n";
        }
        else
        {
            it--;
            cout << *it << endl;
            prices.erase(it);
        }
    }

    return 0;
}