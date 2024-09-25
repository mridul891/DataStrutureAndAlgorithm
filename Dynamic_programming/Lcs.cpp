#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int recusrionLcs(int n, int m, string &text1, string &text2)
{
    if (n < 0 || m < 0)
        return 0;

    if (text1[n - 1] == text2[m - 1])
        return 1 + recusrionLcs(n - 1, m - 1, text1, text2);
    return max(recusrionLcs(n - 1, m, text1, text2), recusrionLcs(n, m - 1, text1, text2));
}

int topdownlcs(int n, int m, string &text1, string &text2, vector<vector<int>> &dp)
{
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n - 1][m - 1];
    if (text1[n - 1] == text2[m - 1])
        return dp[n][m] = 1 + topdownlcs(n - 1, m - 1, text1, text2, dp);
    return dp[n][m] = max(topdownlcs(n - 1, m, text1, text2, dp), topdownlcs(n, m - 1, text1, text2, dp));
}

int bottomuplcs(int n, int m, string &text1, string &text2)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[n - 1] == text2[m - 1])
            {
                dp[n][m] = dp[n - 1][m - 1];
            }
            else
            {
                dp[n][m] = max(dp[n - 1][m], dp[n][m - 1]);
            }
        }
    }
    return dp[n][m];
}

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length();
    int m = text2.length();

    // using recursion
    return recusrionLcs(n, m, text1, text2);

    // using top down apppraoch
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    topdownlcs(n, m, text1, text2, dp);
}