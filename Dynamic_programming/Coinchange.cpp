#include <bits/stdc++.h>
using namespace std;

// Recrusion
int ways(int index, int n, vector<int> &coins, int amount, vector<vector<int>> &dp)
{
    // Recusion
    if (index >= n || amount < 0)
        return 0;
    if (amount == 0)
        return 1;

    int lsum = ways(index, n, coins, amount - coins[index], dp);

    int rsum = ways(index + 1, n, coins, amount, dp);
    return lsum + rsum;
}

// Top Down appraoch
int ways(int index, vector<int> &coins, int amount, vector<vector<int>> &dp)
{
    // top down appraoch dp
    if (index == 0)
        return 0;
    if (amount == 0)
        return 1;

    if (dp[index][amount] != -1)
        return dp[index][amount];

    if (coins[index - 1] > amount)
        return dp[index][amount] = ways(index - 1, coins, amount, dp);
    else
        return dp[index][amount] = ways(index, coins, amount - coins[index - 1], dp) + ways(index - 1, coins, amount, dp);
}

// Bottom up approach
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<long>> dp(n + 1, vector<long>(amount + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
            {
                long long val = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                dp[i][j] = int(val);
            }
        }
    }
    return dp[n][amount];
}

// Main function
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    return ways(0, n, coins, amount, dp);
}
