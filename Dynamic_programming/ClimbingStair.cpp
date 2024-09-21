#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Here we are solving by  taking total energy from the 0th stair to the nth stair

// Recursion

int count(int i, int n)
{

    if (i == n)
        return 1;
    if (i > n)
        return 0;

    return count(i + 1, n) + count(i + 2, n);
}

// Using dynaice Programming
// Top Down Approach

int countUsingTopDown(int i, int n, vector<int> &dp)
{
    if (i == n)
        return 1;
    if (i > n)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    return dp[i] = countUsingTopDown(i + 1, n, dp) + countUsingTopDown(i + 2, n, dp);
}

// BottonmUp Approach

int countUsingBottomUp(int i, int n, vector<int> &dp2)
{
    dp2[n] = 1;
    dp2[n + 1] = 0;

    for (int j = n; j >= 0; j--)
    {
        dp2[i] = dp2[i - 1] + dp2[i - 2];
    }
    return dp2[0];
}
int main()
{
    vector<int> dp(n + 2);
    vector<int> dp2(n + 1);
}