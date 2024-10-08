#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int v = graph.size();

        vector<int> colors(v, -1);
        queue<int> q;

        for (int i = 0; i < v; i++)
        {
            if (colors[i] == -1)
            {
                q.push(i);
                colors[i] = 0;

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for (int j = 0; j < graph[node].size(); j++)
                    {
                        if (colors[graph[node][j]] == -1)
                        {
                            colors[graph[node][j]] = (colors[node] + 1) % 2;
                            q.push(graph[node][j]);
                        }
                        else
                        {
                            if (colors[graph[node][j]] == colors[node])
                                return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
};
 