#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int mincoinchange(vector<int> &coins, int n)
{
    vector<vector<int>> table(coins.size() + 1,vector<int>(n + 1));

    for (int i = 0; i <= n; i++)
        table[0][i] = 0;
    for (int i = 0; i <= coins.size(); i++)
        table[i][0] = 1;
   

    for(int i = 1 ;i<=coins.size();i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(coins[i-1]>j)
            {
                table[i][j] = table[i-1][j]==INT_MAX ? 0: table[i-1][j];
            }
            else
            {
                int prev = table[i-1][j];
                table[i][j] = prev + table[i][j-coins[i-1]];
            }
        }

        for(int j = 0;j<=n;j++)
            cout<<table[i][j]<<"\t";
        cout<<endl;
    }

    return table[coins.size()][n];
}

int main()
{
    vector<int> coins = {5,2,1};
    int cost = 10;

    int mincost = mincoinchange(coins, cost);
    cout << "\nNumber of ways = " << mincost;
}