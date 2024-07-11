#include <iostream>
#include <vector>
using namespace std;

void subsquence(int index, vector<int> &subarr, vector<int> &arr, int size)
{
    if (index == size)
    {
        for (auto i : subarr)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    int element = arr[index];
    subarr.push_back(element);
    subsquence(index + 1, subarr, arr, size);
    subarr.pop_back();
    subsquence(index + 1, subarr, arr, size);
}
int main()
{
    vector<int> arr{3, 1, 2, 4, 5};
    vector<int> subarr;
    int size = 5;
    subsquence(0, subarr, arr, size);
}