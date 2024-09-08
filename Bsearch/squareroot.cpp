#include <iostream>
using namespace std;

int squareroot(int n)
{
    int low = 1;
    int high = n;
    int ans = 1;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (mid * mid == n)
        {
            ans = mid;
            return ans;
        }
        else if (mid * mid > n)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n = 800;
    int square = squareroot(n);
    cout << "ans  is " << square;
}