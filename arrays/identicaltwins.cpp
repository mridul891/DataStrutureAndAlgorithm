// identical twins = for an array of integers nums an identical twin is defined as pair ( i,j) where nums[i] to equal to nums[j] and i<j

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int size;
    vector<int> ans;
    cout << "enter the size " << endl;
    cin >> size;
    cout << "The size is " << size << endl;
    for (int i = 0; i < size; i++)
    {
        int a;
        cout << " Enter the element ";
        cin >> a;
        ans.push_back(a);
    }
    int count = 0;
    cout << " The output is " << endl;
    for (int i = 0; i < size; i++)
    {
        int element = ans[i];
        for (int j = i + 1; j < size; j++)
        {
            if (ans[j] == element && i < j)
            {
                cout << i << " " << j << endl;
                count++;
            }
        }
    }
    cout << "The count is: " << count << endl;
}