#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // creation of queue and visited array
        queue<int> q;
        vector<int> visited(V, 0);
        // pushing the starting Node
        q.push(0);
        // Answer vector to return the answer
        vector<int> ans;

        // Loop till queue becomes not empty
        while (!q.empty())
        {
            // Storing the front element of the queue
            int node = q.front();
            // removeing and adding to the ans array
            q.pop();
            ans.push_back(node);

            // Lopping to mark all the node childs as visited as 1 and adding it to the queue
            for (int i = 0; i < adj[node].size(); i++)
            {
                if (!visited[adj[node][i]])
                {
                    visited[adj[node][i]] = 1;
                    q.push(adj[node][i]);
                }
            }
        }
        // return the answer
        return ans;
    }
};