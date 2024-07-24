#include <iostream>
#include <string>

using namespace std;

// Recursive function to generate all contiguous substrings
void generateSubstringsRecursively(const string &str, string current, int start, int index)
{
    if (index == str.length())
    {
        return;
    }

    current += str[index];
    cout << current << endl;

    // Generate next substring starting from the next character
    generateSubstringsRecursively(str, current, start, index + 1);

    // Generate new substring starting from the next character of the original string
    if (current.length() == 1)
    {
        generateSubstringsRecursively(str, "", start + 1, start + 1);
    }
}

// Wrapper function to start the recursion
void generateAllSubstrings(const string &str)
{
    generateSubstringsRecursively(str, "", 0, 0);
}

int main()
{
    string str = "mridul";
    generateAllSubstrings(str);
    return 0;
}
