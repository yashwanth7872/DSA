#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool check(int i , int sum, int count,vector<int> &arr,vector<int> &res)
{
    if(count == 0) return sum == 0;
    if(i>=arr.size()) return false;

    if(arr[i] <= sum)
    {
        res.push_back(arr[i]);
        if(check(i+1,sum - arr[i],count-1,arr,res))
            return true;
        res.pop_back();
    } 

    if(check(i+1,sum,count,arr,res))
        return true;
    return false;
}

void partition(vector<int> arr)
{
    int n = arr.size();
    int S = 0;
    for(int i : arr)
    {
        S+=i;
    }

    for(int i = 1;i<n;i++)
    {
        if((S * i)%n==0)
        {
            int s1 = (S*i)/n;

            vector<int> res;

            if(check(0,s1,i,arr,res))
            {
                for(int j : res)
                    cout<<j<<"  ";
                cout<<endl;

            }
        }
    }
}



int main()
{

    vector<int> arr = {1,2,3,4,5,6};
    partition(arr);

    return 0;
}
