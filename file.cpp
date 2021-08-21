#include <iostream>
#include <bits/stdc++.h>
#include "time.cpp"
using namespace std;


int lis(vector<int> &A)
{
    int maxi = INT_MIN;
    int n = A.size();

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(i==j) 
            {
                maxi = max(maxi,0);
            }
            else
            {
                int ans = abs(A[i] - A[j]) + abs(i-j);
                maxi = max(ans,maxi);
            }
        }
    }

    return maxi;
}


int main()
{
    TIMESTART
    vector<int>  arr = {1, 3, -1};
    cout<<lis(arr);

    TIMEEND
    return 0;
}
