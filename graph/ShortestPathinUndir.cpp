#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edge, int N, int M, int src)
    {
        // code here
        vector<int> adj[N];

        // adjanceny list
        for (int i = 0; i < M; i++)
        {
            adj[edge[i][0]].push_back(edge[i][1]);
            adj[edge[i][1]].push_back(edge[i][0]);
        }

        vector<int> dist(N, -1);
        vector<bool> visit(N, 0);

        queue<int> q;
        q.push(src);
        dist[src] = 0;
        visit[src] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int j = 0; j < adj[node].size(); j++)
            {
                if (!visit[adj[node][j]])
                {
                    visit[adj[node][j]] = 1;
                    dist[adj[node][j]] = dist[node] + 1;
                    q.push(adj[node][j]);
                }
            }
        }

        return dist;
    }
};