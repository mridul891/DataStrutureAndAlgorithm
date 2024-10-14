#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int row[4] = {0, 0, -1, 1};
    int col[4] = {-1, 1, 0, 0};

    bool isValid(int i, int j, int rows, int cols)
    {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }
    int helpaterp(vector<vector<int>> hospital)
    {
        int rows = hospital.size();
        int cols = hospital[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (hospital[i][j] == 2)
                {
                    q.push(make_pair(i, j));
                }
            }
        }

        int timer = 0;
        while (!q.empty())
        {
            timer++;
            int curr_covid_patient = q.size();

            while (curr_covid_patient--)
            {
                int i = q.front().first;
                int j = q.front().second;

                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    if (isValid(i + row[k], j + col[k], rows, cols) && hospital[i + row[k]][j + col[k]] == 1)
                    {
                        hospital[i + row[k]][j + col[k]] = 2;
                        q.push(make_pair(i + row[k], j + col[k]));
                    }
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (hospital[i][j] == 1)
                    return -1;
            }
        }
        return timer == 0 ? 0 : timer - 1;
    }
};