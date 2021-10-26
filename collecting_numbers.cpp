#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n,0);
    vector<int> position(n,0);
    for(int i=0 ; i<n ; i++)
    {
        cin >> nums[i];
        nums[i]--;
        position[nums[i]] = i;
    }
    int passes=1;
    for(int i=1 ; i<n ; ++i)
    {
        if(position[i] < position[i-1]) passes++;
    }
    cout << passes << endl;

    return 0;
}
