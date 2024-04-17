#include <vector>
#include <pair>

// this is using the extra space 
class SpecialStack
{
public:
    vector<pair<int, int>> st;
    void push(int data)
    {
        // Implement the push() function.
        if (st.empty())
        {
            // means  inserting first element
            pair<int, int> p;
            p.first = data;
            p.second = data;
            st.push_back(p);
        }
        else
        {
            pair<int, int> p;
            p.first = data;
            int previousMin = st.back().second;
            p.second = min(data, previousMin);
            st.push_back(p);
        }
    }

    void pop()
    {
        // Implement the pop() function.
        st.pop_back();
    }

    int top()
    {
        // Implement the top() function.
        pair<int, int> rightmostElement = st.back();
        return rightmostElement.first;
    }

    int getMin()
    {
        // Implement the getMin() function.
        pair<int, int> minimum = st.back();
        return minimum.second;
    }
};