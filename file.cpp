#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxcollected(int i,int n,int k,int arr[])
{
    if(i>=n) return 0;
    int left = maxcollected(i+1,n,k,arr);
    int right = arr[i] + maxcollected(i+1+k,n,k,arr);
    return max(left,right);
}

int main()
{
    int n;
    char *s;
    cin>>n>>s;
    s[0] = '0';
    int k = atoi(s);
    cout<<k;
    // int arr[n];
    // for(int i = 0;i < n;i++)
    // {
    //     cin>>arr[i];
    // }
    // cout<<maxcollected(0,n,k,arr);
}
