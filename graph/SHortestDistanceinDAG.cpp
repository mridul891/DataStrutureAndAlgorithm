#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void DFS(vector<pair<int, int>> adj[], int node, stack<int> &s, vector<bool> visited)
    {
        visited[node] = 1;

        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!visited[adj[node][i].first])
            {
                DFS(adj, adj[node][i].first, s, visited);
            }
        }
        s.push(node);
    }
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // code here

        // create adjancey list
        vector<pair<int, int>> adj[N];

        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];

            adj[u].push_back(make_pair(v, weight));
        }
        // topological sort
        vector<bool> visited(N, 0);
        stack<int> s;
        DFS(adj, 0, s, visited);
        // create stack

        vector<int> dist(N, INT_MAX);
        dist[0] = 0;
        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            // look at neighbour
            for (int i = 0; i < adj[node].size(); i++)
            {
                int neigh = adj[node][i].first;
                int wt = adj[node][i].second;

                dist[neigh] = min(dist[neigh], wt + dist[node]);
            }
        }
        // Intitliaze with -1
        for (int i = 0; i < N; i++)
        {
            if (dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};