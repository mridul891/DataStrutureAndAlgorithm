#include <iostream>
#include <vector>
using namespace std;
// Adjacency matrix

// Undirected unweighted graph
int undirunwei(vector<vector<bool>> &AdjMatrix, int vertex, int edges)
{
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        AdjMatrix[u][v] = 1;
        AdjMatrix[v][u] = 1;
    }

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            cout << AdjMatrix[i][j];
        }
        cout << endl;
    }
}

// Undirected weighted graph
int UnDirWei(vector<vector<bool>> &AdjMatrix1, int vertex, int edges)
{
    int u, v, weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;
        AdjMatrix1[u][v] = weight;
        AdjMatrix1[v][u] = weight;
    }

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            cout << AdjMatrix1[i][j];
        }
        cout << endl;
    }
}

// directed unweighted graph
int dirUnWei(vector<vector<bool>> &AdjMatrix2, int vertex, int edges)
{
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        AdjMatrix2[u][v] = 1;
    }

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            cout << AdjMatrix2[i][j];
        }
        cout << endl;
    }
}

// directed weighted graph
int DirWei(vector<vector<bool>> &AdjMatrix3, int vertex, int edges)
{
    int u, v, weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;
        AdjMatrix3[u][v] = weight;
    }

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            cout << AdjMatrix3[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    // Undirected unweighted graph
    vector<vector<bool>> AdjMatrix(vertex, vector<bool>(vertex, 0));

    // Undirected  weighted graph
    vector<vector<int>> AdjMatrix1(vertex, vector<int>(vertex, 0));

    // Directed unwieghted graph
    vector<vector<bool>> AdjMatrix2(vertex, vector<bool>(vertex, 0));

    // Direct weighted Graph
    vector<vector<int>> AdjMatrix3(vertex, vector<int>(vertex, 0));
}