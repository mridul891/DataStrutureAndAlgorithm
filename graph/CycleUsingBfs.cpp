#include <iostream>
using namespace std;
#include <bits/stdc++.h>
bool isDetected(int vertex, vector<int> adj[], vector<bool> &visited)
{

    queue<pair<int, int>> q;
    visited[vertex] = 1;
    q.push(make_pair(vertex, -1));

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int j = 0; j < adj[node].size(); j++)
        {
            if (parent == adj[node][j])
                continue;
            if (visited[adj[node][j]])
                return 1;
            else
            {
                visited[adj[node][j]] = 1;
                q.push(make_pair(adj[node][j], node));
            }
        }
    }
    return 0;
}

bool isCycle(vector<int> adj[], int v)
{

    vector<bool> visited(v, 0);

    for (int i = 0; i < v; i++)
    {

        if (!visited[i] && isDetected(i, adj, visited))
            return 1;
    }
    return 0;
}