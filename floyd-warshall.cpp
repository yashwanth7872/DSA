#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<tuple<int, int, int>> &edges, int u, int v, int w)
{
    edges.push_back(make_tuple(u, v, w));
}

void floyd(vector<tuple<int, int, int>> &edges , int n)
{
    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

    for(int i = 0;i<n;i++)
        dist[i][i] = 0;
    
    for (auto j : edges)
    {
        int u = get<0>(j);
        int v = get<1>(j);
        int w = get<2>(j);
        dist[u][v] = w;
    }

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cout<<dist[i][j]<<"\t";
        }

        cout<<endl;
    }
    

    for(int k = 0;k<n;k++)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
            }
        }
    }
   for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cout<<dist[i][j]<<"\t";
        }

        cout<<endl;
    }
    
}

int main()
{
    int n = 4;
    vector<vector<pair<int, int>>> graph(n);
    vector<tuple<int, int, int>> edges(n);
    addEdge(edges, 0, 1, 1);
    addEdge(edges, 1, 2, -1);
    addEdge(edges, 2, 3, -1);
    addEdge(edges, 3, 0, -1);
    floyd(edges,n);

    return 0;
}