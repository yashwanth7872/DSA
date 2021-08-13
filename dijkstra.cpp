#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<pair<int, int>>> &graph, int source)
{
    queue<int> q;
    vector<bool> arr(graph.size(), 0);
    arr[source] = 1;
    q.push(source);
    cout << "\nBFS Traversal\n";
    while (!q.empty())
    {
        int x = q.front();
        cout << x << "\t";
        q.pop();
        for (int i = 0; i < graph[x].size(); i++)
        {
            int j = graph[x][i].first;
            if (arr[j] != 1)
            {
                q.push(j);
                arr[j] = 1;
            }
        }
    }
}

void display(vector<vector<pair<int, int>>> &graph)
{
    for (int j = 0; j < graph.size(); j++)
    {
        cout << j << "-->";
        for (auto i = graph[j].begin(); i != graph[j].end(); i++)
        {
            cout << "(" << i->first << "," << i->second << ") ";
        }
        cout << endl;
    }
}
void addEdge(vector<vector<pair<int, int>>> &graph, int u, int v, int w)
{
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}

void dij(vector<vector<pair<int, int>>> &graph, int source)
{
    vector<int> dist(graph.size(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));
    dist[source] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Vertex      Distance from Source" << endl;
    for (int i = 0; i < graph.size(); i++)
        cout << i << "\t\t" << dist[i] << endl;
}
int main()
{
    int n = 6;
    vector<vector<pair<int, int>>> graph(n);
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 2, 3, 5);
    addEdge(graph, 1, 3, 4);
    addEdge(graph, 2, 4, 5);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 3, 5, 1);
    addEdge(graph, 4, 5, 2);
    display(graph);
    dij(graph, 5);
    bfs(graph, 0);
    return 0;
}