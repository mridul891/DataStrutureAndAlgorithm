#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int row[4] = {0, 0, -1, 1};
    int col[4] = {-1, 1, 0, 0};
    int rows;
    int cols;

    bool isValid(int i, int j)
    {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        rows = n, cols = m;
        queue<pair<int, int>> q;

        // Travseres the boundary if any O found mark all its connectd O as  T;

        // first row

        for (int j = 0; j < cols; j++)
        {
            if (mat[0][j] == 'O')
            {
                q.push(make_pair(0, j));
                mat[0][j] = 'T';
            }
        }

        // first column
        for (int j = 0; j < rows; j++)
        {
            if (mat[j][0] == 'O')
            {
                q.push(make_pair(j, 0));
                mat[j][0] = 'T';
            }
        }

        // last row
        for (int j = 1; j < cols; j++)
        {
            if (mat[rows - 1][j] == 'O')
            {
                q.push(make_pair(rows - 1, j));
                mat[rows - 1][j] = 'T';
            }
        }

        // last column
        for (int j = 1; j < rows; j++)
        {
            if (mat[j][cols - 1] == 'O')
            {
                q.push(make_pair(j, cols - 1));
                mat[j][cols - 1] = 'T';
            }
        }

        while (!q.empty())
        {

            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            for (int k = 0; k < 4; k++)
            {
                if (isValid(i + row[k], j + col[k]) && mat[i + row[k]][j + col[k]] == 'O')
                {
                    mat[i + row[k]][j + col[k]] = 'T';
                    q.push(make_pair(i + row[k], j + col[k]));
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j] == 'T')
                {
                    mat[i][j] = 'O';
                }
                else
                {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};