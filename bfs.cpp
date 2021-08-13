#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int g[10][10] = {0};
    int n;

public:
    void read_data()
    {
        cout << "Enter no. of vertices : ";
        cin >> n;
        cout << n;
        cout << "Enter adjacency matrix\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> g[i][j];
    }

    void display_data()
    {
        cout << "Adjacency matrix\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << g[i][j] << "\t";
            cout << endl;
        }
    }

    void bfs(int source)
    {
        queue<int> q;
        int arr[n] = {0};
        q.push(source);
        arr[source] = 1;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            cout << x << "\t";
            for (int i = 0; i < n; i++)
                if (g[x][i] == 1 && arr[i] != 1)
                {
                    q.push(i);
                    arr[i] = 1;
                }
        }
        cout<<endl;
    }

    void dfs(int source)
    {
        stack<int> s;
        int arr[n] = {0};
        s.push(source);
        arr[source] = 1;
        while (!s.empty())
        {
            int x = s.top();
            s.pop();
            
            cout << x << "\t";
            for (int i = 0; i < n; i++)
                if (g[x][i] == 1 && arr[i] != 1)
                {
                    s.push(i);
                    arr[i] = 1;
                }
        }
        cout<<endl;
    }

    void dfs_rec(int source,vector<bool> &arr)
    {
        arr[source] = 1;
        cout<<source<<"\t";
        for (int i = 0; i < 5; i++)
            if (g[source][i] == 1 && arr[i] != 1)
            {
                dfs_rec(i,arr);
            }

    }
};

int main()
{
    Graph g;
    vector<bool> arr(5,0);
    g.read_data();
    g.display_data();
    g.dfs(2);
    g.dfs_rec(2,arr);
    return 0;
}