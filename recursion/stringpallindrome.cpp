#include <iostream>
using namespace std;

bool pallindrome(string &s, int low, int high)
{
    if (low >= high)
        return true;
    if (s[low] != s[high])
        return false;
    return pallindrome(s, low + 1, high - 1);
}
int main()
{
    string s = "madam";
    int size = s.size();
    int low = 0;
    int high = size - 1;
    bool a = pallindrome(s, low, high);
    return 0;
}