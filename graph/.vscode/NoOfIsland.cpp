#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find the number of islands.
    int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int rows, cols;
    bool isValid(int i, int j)
    {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here

        rows = grid.size();
        cols = grid[0].size();

        queue<pair<int, int>> q;

        int count = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {

                    count++;
                    q.push(make_pair(i, j));
                    grid[i][j] = '0';

                    while (!q.empty())
                    {
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();
                        for (int k = 0; k < 8; k++)
                        {
                            if (isValid(new_i + row[k], new_j + col[k]) && grid[new_i + row[k]][new_j + col[k]] == '1')
                            {
                                grid[new_i + row[k]][new_j + col[k]] = '0';
                                q.push(make_pair(new_i + row[k], new_j + col[k]));
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};