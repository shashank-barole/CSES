#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t ;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> power_of_prime;
        for(int i=2 ; i*i <= n ;++i)
        {
            if(n%i==0)
            {
                int power=0;
                while (n%i==0)
                {
                    power++;
                    n/=i;
                }
                power_of_prime.push_back(power);
            }
        }
        if(n!=1)power_of_prime.push_back(1);
        long long res=1;
        for(auto i:power_of_prime) res*=(i+1);
        cout << res << endl;
    }
    

    return 0;
}