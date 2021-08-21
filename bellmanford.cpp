#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<tuple<int, int, int>> &edges, int u, int v, int w)
{
    edges.push_back(make_tuple(u, v, w));
}

void bellmanford(vector<tuple<int, int, int>> &edges, int source, int n)
{
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;
    bool cycle = 0;

    for (int i = 1; i < n; i++)
    {
        for (auto j : edges)
        {
            int u = get<0>(j);
            int v = get<1>(j);
            int w = get<2>(j);
            if (dist[u]!=INT_MAX && dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }

    for (auto j : edges)
    {
        int u = get<0>(j);
        int v = get<1>(j);
        int w = get<2>(j);
        if (dist[u]!=INT_MAX && dist[v] > dist[u] + w)
            cycle = 1;
    }

    for (auto i : dist)
        cout << i << endl;
    
    cout<<"\nCycle"<<(cycle?" is present":" is not present");
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
    bellmanford(edges, 1, n);

    return 0;
}