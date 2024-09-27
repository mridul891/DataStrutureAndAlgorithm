#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int lpsrecursion(string &text1, string &text2, int n, int m)
{
    if (n < 0 || m < 0)
        return 0;
    if (text1[n - 1] == text2[m - 1])
        return 1 + (text1, text2, n - 1, m - 1);
    return max(lpsrecursion(text1, text2, n - 1, m), lpsrecursion(text1, text2, n, m - 1));
}

// Top down approach
int lpstopdown(string &text1, string &text2, int n, int m, vector<vector<int>> &dp)
{
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (text1[n - 1] == text2[m - 1])
        return dp[n][m] = 1 + (text1, text2, n - 1, m - 1);
    return dp[n][m] = max(lpsrecursion(text1, text2, n - 1, m), lpsrecursion(text1, text2, n, m - 1));
}

int lpsbottomup(string &text1, string &text2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[n - 1] == text2[m - 1])
                dp[n][m] = dp[n - 1][m - 1];
            else
            {
                dp[n][m] = max(dp[n - 1][m], dp[n][m - 1]);
            }
        }
    }

    return dp[n][m];
}

// space optimization

int lpsspaceOpti(string &text1, string &text2, int n, int m)
{
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[n - 1] == text2[m - 1])
                curr[m] = prev[m - 1];
            else
            {
                curr[m] = max(prev[m], curr[m - 1]);
            }
        }
        prev = curr;
    }

    return curr[m];
}

int longestpallindromesubsequence(string text1)
{
    string text2 = text1;
    reverse(text2.begin(), text2.end());
    int n = text1.length();
    int m = text2.length();

    // recursion
    lpsrecursion(text1, text2, n, m);

    // top down approach
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    lpstopdown(text1, text2, n, m, dp);

    // bottom up approach
    lpsbottomup(text1, text2, n, m);
}