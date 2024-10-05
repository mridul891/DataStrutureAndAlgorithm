#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// undirected unweighted graph
void UnDirUnWei(int vertex, int edges)
{
    vector<int> adjlist[vertex];

    int u, v;

    for (int i = 0; i < edges; i++)
    {
        vector<int> arr;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    for (int i = 0; i < edges; i++)
    {
        cout << i << "->";
        for (int j = 0; j < adjlist[i].size(); j++)
        {
            cout << adjlist[i][j];
        }
        cout << endl;
    }
}

// Undirected Weighted Graph
void UnDirWei(int vertex, int edges)
{
    vector<pair<int, int>> adjlist[vertex];

    int u, v, weights;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weights;
        adjlist[u].push_back(make_pair(v, weights));
        adjlist[v].push_back(make_pair(u, weights));
    }

    // Printing
    for (int i = 0; i < vertex; i++)
    {
        cout << i << "->";
        for (int j = 0; j < adjlist[i].size(); j++)
        {
            cout << adjlist[i][j].first << " " << adjlist[i][j].second;
        }
        cout << endl;
    }
}

// directed unweighted graph
void DirUnWei(int vertex, int edges)
{
    vector<int> adjlist[vertex];

    int u, v;

    for (int i = 0; i < edges; i++)
    {
        vector<int> arr;
        cin >> u >> v;
        adjlist[u].push_back(v);
    }

    for (int i = 0; i < edges; i++)
    {
        cout << i << "->";
        for (int j = 0; j < adjlist[i].size(); j++)
        {
            cout << adjlist[i][j];
        }
        cout << endl;
    }
}

// directed Weighted Graph
void DirWei(int vertex, int edges)
{
    vector<pair<int, int>> adjlist[vertex];

    int u, v, weights;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weights;
        adjlist[u].push_back(make_pair(v, weights));
    }

    // Printing
    for (int i = 0; i < vertex; i++)
    {
        cout << i << "->";
        for (int j = 0; j < adjlist[i].size(); j++)
        {
            cout << adjlist[i][j].first << " " << adjlist[i][j].second;
        }
        cout << endl;
    }
}

int main()
{

    int vertex, edges;
    cin >> vertex >> edges;
}