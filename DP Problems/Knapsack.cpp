#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int knapsack(int i , int w ,vector<int> &weights,vector<int> & values)
{

    if(w < 0) return INT_MIN;
    if(i>=weights.size()) return 0;

    int left = values[i] + knapsack(i+1,w-weights[i],weights,values);
    int right = knapsack(i+1,w,weights,values);

    return max(left , right);
}


int main()
{
    //TIMESTART

    vector<int> weights = {3,4,5};
    vector<int> values = {30,40,60};

    cout<<knapsack(0,8,weights,values);
    //TIMEEND
    return 0;
}
