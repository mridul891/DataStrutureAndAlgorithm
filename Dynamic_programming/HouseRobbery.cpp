#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// We have to find the maximum amount of robbery
// COndition = cannot robber from 2 adjacent houses

int Robbery(int n, vector<int> &nums)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];

    return max(nums[n] + Robbery(n - 2, nums), Robbery(n - 1, nums));
}
Robbery(n - 1, nums);
// Top Down approach
int RobberyUsingTopDown(int n, vector<int> &nums, vector<int> &dp)
{
    if (n == 0)
        return nums[0];
    if (n == 1)
        return max(nums[0], nums[1]);

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = max(nums[n] + RobberyUsingTopDown(n - 2, nums, dp), RobberyUsingTopDown(n - 1, nums, dp));
}

// Bottom Up approach
int RobberyUsingBottomUp(int n, vector<int> &nums)
{
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(nums[n] + dp[i - 2], dp[i - 1]);
    }
    return dp[n - 1];
}