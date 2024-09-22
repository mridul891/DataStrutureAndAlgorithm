#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// Recursion
int count(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    return count(n - 1) + count(n - 2) + count(n - 3);
}

// Top Down Approach
vector<int> dp(n, -1);
int countUsingTopDown(int n, vector<int> &dp)
{
    if (n == 2)
        return 2;
    if (n <= 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = count(n - 1) + count(n - 2) + count(n - 3);
}

// Bottom up approach
vector<int> dp(n);
int countUsingBottomUp(int n, vector<int> &dp)
{
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}
