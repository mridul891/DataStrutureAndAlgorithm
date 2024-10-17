#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find total number of unique paths.

    // Recursion
    int noOfways(int i, int j, int a, int b)
    {

        if (i > a || j > b)
            return 0;
        if (i == a && j == b)
            return 1;

        return noOfways(i + 1, j, a, b) + noOfways(i, j + 1, a, b);
    }
    int NumberOfPath(int a, int b)
    {
        // code here

        // Botton up approach
        // code here
        vector<vector<int>> dp(a, vector<int>(b, 1));

        for (int i = a - 2; i >= 0; i--)
        {
            for (int j = b - 2; j >= 0; j--)
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
        // space optimzation
        vector<int> dp(b, 1);
        for (int i = a - 2; i >= 0; i--)
        {
            for (int j = b - 2; j >= 0; j--)
            {
                dp[j] += dp[j + 1];
            }
        }
        return dp[0];
    }
};