#include <bits/stdc++.h>
using namespace std;

bool isCycle(int v, vector<int> adj[])
{
    vector<int> ans;
    vector<int> indeg(v, 0);

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            indeg[adj[i][j]]++;
        }
    }

    queue<int> q;
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        if (!indeg[i])
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        count++;
        for (int i = 0; i < adj[node].size(); i++)
        {
            indeg[adj[node][i]]--;
            if (indeg[adj[node][i]] == 0)
                q.push(adj[node][i]);
        }
    }
    return count != v;
}