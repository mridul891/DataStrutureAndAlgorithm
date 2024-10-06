#include <bits/stdc++.h>
using namespace std;

void sort(int vertex, vector<int> adj[], vector<bool> &visited, stack<int> &s)
{

    visited[vertex] = 1;

    for (int j = 0; j < adj[vertex].size(); j++)
    {
        if (!visited[adj[vertex][j]])
        {

            sort(adj[vertex][j], adj, visited, s);
        }
    }

    s.push(vertex);
}
vector<int> topoSort(int v, vector<int> adj[])
{
    // code here
    vector<int> ans;
    stack<int> s;
    vector<bool> visited(v, 0);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            sort(i, adj, visited, s);
    }

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}