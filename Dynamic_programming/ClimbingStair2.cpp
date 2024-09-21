#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Here we are finding total steps taken  to reach nth stair from nth stair to 0th starir

// recursion
int ways(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;

    return ways(n - 1) + ways(n - 2);
}

// Top down approach
int countUsingTopDown(int n, vector<int> &dp)
{

    if (n <= 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = countUsingTopDown(n - 1, dp) + countUsingTopDown(n - 2, dp);
}

// Bottomupapproach
int countUsingBottomUp(int n, vector<int> &dp)
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// space optimazation
int countUsingSpaceOptimization(int n)
{
    int prev = 1;
    int prev1 = 1;
    int curr;
    for (int i = 2; i <= n; i++)
    {
        curr = prev + prev1;
        prev = prev1;
        prev1 = curr;
    }
    return curr;
}
int main()
{
}