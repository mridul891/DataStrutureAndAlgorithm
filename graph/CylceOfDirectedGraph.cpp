#include <bits/stdc++.h>
using namespace std;

bool isDetect(int node, vector<int> adj[], vector<int> &path, vector<int> &visited)
{
    path[node] = 1;
    visited[node] = 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (path[adj[node][j]])
            return 1;
        if (visited[adj[node][j]])
            continue;
        if (isDetect(node, adj, path, visited))
            return 1;
    }
    path[node] = 0;
    return 0;
}

bool isCycle(int v, vector<int> adj[])
{
    vector<bool> visited(v, 0);
    vector<bool> path(v, 0);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && isDetect(i, adj, path, visited))
            return 1;
    }
    return 0;
}