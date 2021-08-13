#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
}

void toposort_kahn(vector<vector<int>> &graph)
{
    int n = graph.size();
    queue<int> q;
    vector<int> indegree(n, 0), result;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < graph[i].size(); j++)
            indegree[graph[i][j]]++;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        result.push_back(x);
        for (int i = 0; i < graph[x].size(); i++)
        {
            int y = graph[x][i];
            indegree[y]--;
            if (indegree[y] == 0)
                q.push(y);
        }
    }

    cout << "\nTopological Sorting\n";
    for (int c : result)
        cout << c << "\t";
}

void toposort(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &res, int source)
{
    visited[source] = 1;
    for (int i = 0; i < graph[source].size(); i++)
    {
        if (visited[graph[source][i]] != 1)
            toposort(graph, visited, res, graph[source][i]);
    }
    res.push_back(source);
}
int main()
{
    int n = 5;
    vector<vector<int>> graph(n);
    vector<bool> visited(n, 0);
    vector<int> res;
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 2);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    toposort_kahn(graph);
    toposort(graph, visited, res, 0);
    cout << "\nTopological Sorting\n";
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << "\t";
}