#include <iostream>
#include <bits/stdc++.h>
#include "time.cpp"
using namespace std;


int lis(vector<int> arr)
{
    int n = arr.size();

    vector<int> ans;
    ans.push_back(arr[0]);

    for(int i = 1;i<n;i++)
    {
        if(ans.back() < arr[i])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            int ind = lower_bound(ans.begin(),ans.end(),arr[i]) - ans.begin();
            ans[ind] = arr[i];
        }
    }
    
    return ans.size();
}


int main()
{
    TIMESTART
    vector<int>  arr = {10,2,5,7,3,1};
    cout<<lis(arr);

    TIMEEND
    return 0;
}
