#include <bits/stdc++.h>
using namespace std;

// Recursion
int find(int index, int wt[], int val[], int W)
{

    // base condition
    if (W == 0 || index == 0)
        return 0;

    if (wt[index - 1] > W)
        return find(index - 1, wt, val, W);
    else
        return max(val[index - 1] + find(index - 1, wt, val, W - wt[index - 1]), find(index - 1, wt, val, W));
}

// Top down approach
int findUsingTopDown(int index, int wt[], int val[], int W, vector<vector<int>> &dp)
{
    if (W == 0 || index == 0)
        return 0;

    if (dp[index][W] != -1)
        return dp[index][W];
    if (wt[index - 1] > W)
        return dp[index][W] = findUsingTopDown(index - 1, wt, val, W, dp);
    else
        return dp[index][W] = max(val[index - 1] + findUsingTopDown(index - 1, wt, val, W - wt[index - 1]), findUsingTopDown(index - 1, wt, val, W));
}

// Bottom Up
int findUsingBottomUp(int n, int wt[], int val[], int W, vector<vector<int>> &dp)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (wt[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
        }
    }
    return dp[n][W];
}

// space optimization
int findUsingSpaceOptimization(int n, int wt[], int val[], int W, vector<vector<int>> &dp)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = W; j > 0; j--)
        {
            if (wt[i - 1] <= j)
            {
                dp[j] = max(dp[j - wt[i - 1]], dp[j]);
            }
        }
    }
    return dp[W];
}

int knapsack(int wt[], int val[], int W, int n)
{

    // top down appraoch
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    findUsingTopDown(n, wt, val, W, dp);

    // bottom up approach
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    findUsingBottomUp(n, wt, val, W, dp);

    // space optimization
    vector<int> dp(W + 1, 0);
    findUsingSpaceOptimization(n, wt, val, W, dp);
}