#include <bits/stdc++.h>
using namespace std;

bool checkBipartite(int node, vector<int> adj[], vector<int> &color)
{

    color[node] = 0;

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (color[adj[node][j]] == -1)
        {
            color[adj[node][j]] = (color[node] + 1) % 2;
            if (!checkBipartite(adj[node][j], adj, color))
                return 0;
        }
        else
        {
            if (color[node] == color[adj[node][j]])
                return 0;
        }
    }
    return 1;
}

bool isBipartite(int v, vector<int> adj[])
{
    vector<int> color(v, -1);
    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            if (!checkBipartite(i, adj, color))
                return 0;
        }
    }
    return 1;
}