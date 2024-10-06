#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool CycleDetected(int node, int parent, vector<int> &visited, vector<bool> adj[])
{
    visited[node] = 1;
    for (int j = 0; j < adj[node].size(); j++)
    {
        if (parent == adj[node][j])
            continue;
        if (visited[adj[node][j]] == 1)
            return 1;
        if (CycleDetected(adj[node][j], node, visited, adj))
            return 1;
    }

    return 0;
}

bool isCycle(int v, vector<int> adj[])
{
    vector<bool> visited(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && CycleDetected(0, -1, visited, adj))
        {
            return 1;
        }
    }
    return 0;
}