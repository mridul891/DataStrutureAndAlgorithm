#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<int> adj[], int v)
{

    vector<int> indeg(v, 0);
    vector<int> ans;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            indeg[adj[i][j]]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (!indeg[i])
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();

        for (int j = 0; j < adj[node].size(); j++)
        {
            indeg[adj[node][j]]--;
            if (indeg[adj[node][j]] == 0)
            {
                q.push(adj[node][j]);
            }
        }
    }
    return ans;
}