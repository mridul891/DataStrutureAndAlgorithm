#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int RobberyRecursion(int index, int n, vector<int> &nums)
{

    if (n < index)
        return 0;
    if (n == index)
        return nums[index];

    return max(nums[n] + RobberyRecursion(index, n - 2, nums), RobberyRecursion(index, n - 1, nums));
}

// Top down approach
int RobberyTopDown(int index, int n, vector<int> &nums, vector<int> dp)
{

    if (n < index)
        return 0;
    if (n == index)
        return nums[index];

    if (dp[n] != -1)
        return dp[n];
    return dp[n] = max(nums[n] + RobberyTopDown(index, n - 2, nums, dp), RobberyTopDown(index, n - 1, nums, dp));
}

int rob(vector<int> &nums)
{
    int n = nums.size();

    // Recursion
    if (nums.size() == 1)
        return nums[0];
    return max(RobberyRecursion(0, n - 2, nums),
               RobberyRecursion(1, n - 1, nums));

    // Top down approach
    if (nums.size() == 1)
        return nums[0];
    vector<int> dp1(n + 1, -1);
    vector<int> dp2(n + 1, -1);
    return max(RobberyTopDown(0, n - 2, nums, dp1),
               RobberyTopDown(1, n - 1, nums, dp2));
    
    // Bottom up approach 

}