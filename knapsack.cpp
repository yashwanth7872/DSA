/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int knapsack(vector<int> &w,vector<int> &p,int m)
{
    vector<vector<int>> table(w.size()+1,vector<int>(m+1,0));
    
    for(int i = 1;i<=w.size();i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(w[i-1] > j)
            {
                table[i][j] = table[i-1][j];
            }
            else
            {
                table[i][j] = max(table[i-1][j] , p[i-1] + table[i-1][j - w[i-1]]);
            }
        }
    }
    
    return table[w.size()][m];
}
int main()
{
    vector<int> w = {2,3,4,5},p = {1,2,5,6};
    int m = 8;
    int maxprofit = knapsack(w,p,m);
    cout<<maxprofit;
    return 0;
}
