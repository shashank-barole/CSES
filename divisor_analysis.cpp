#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const int MOD = 1e9 + 7;


lli bin_exp(lli a,lli b)
{
    lli res=1;
    while (b)
    {
        if(b&1)
        {
            res = (res *a)%MOD;
            b-=1;
        }
        else
        {
            a = (a * a)%MOD;
            b/=2;
        }
    }
    return res;
}


lli number_of_divisors(unordered_map<lli,lli>& prime_fact)
{
    lli total=1;
    for(auto i:prime_fact)
    {
        total = (total *  (i.second+1))%MOD;
    }
    return total;
}

lli sum_of_factors(unordered_map<lli,lli>& prime_fact)
{
    lli total=1;
    for(auto i:prime_fact)
    {
        lli numerator = (bin_exp(i.first,i.second+1)-1)%MOD;
        lli denominator = bin_exp(i.first-1,MOD-2);
        lli product = (numerator * denominator)%MOD;
        total = (total*product)%MOD;
    }
    return total;
}
int main()
{
    int parts;
    cin >> parts;
    unordered_map<lli,lli> prime_factorization;
    while (parts--)
    {
        int base,power;
        cin >> base >> power;
        prime_factorization[base]=power;
    }
    lli num_divisors = number_of_divisors(prime_factorization);
    lli sum_divisors = sum_of_factors(prime_factorization);
    lli product_divisors=1;
    bool oddExponent=false;
    int positionOfOddExponent;
    for( auto& i: prime_factorization)
    {
        if(i.second&1)
        {
            oddExponent=true;
            positionOfOddExponent = i.first;
        }
    }
    if(oddExponent)
    {
        lli outerExponent = 1;
        for(auto& i:prime_factorization)
        {
            if(i.first == positionOfOddExponent)
            {
                outerExponent = (outerExponent * (i.second+1)/2)%(MOD-1);
            }
            else
            {
                outerExponent = (outerExponent * (i.second+1))%(MOD-1);
            }
        }
        for(auto i: prime_factorization)
        {
            product_divisors = (product_divisors * bin_exp(i.first,(i.second*outerExponent)%(MOD-1)))%MOD;
        }
    }
    else
    {
        lli outerExponent=1;
        for(auto& i : prime_factorization)
        {
            outerExponent = (outerExponent * (i.second+1))%(MOD-1);
        }
        for(auto& i:prime_factorization)
        {
            product_divisors = (product_divisors * bin_exp(i.first,((i.second/2)*outerExponent)%(MOD-1)))%MOD;
        }
    }
    cout << num_divisors << " " << sum_of_factors(prime_factorization) << " " << product_divisors;

    
    return 0;
}