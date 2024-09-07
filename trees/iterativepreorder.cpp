#include <iostream>
#include <vector>
using namespace std;
// template <typename T>
//     class TreeNode {
//        public:
//         T data;
//         TreeNode<T> *left;
//         TreeNode<T> *right;

//         TreeNode(T data) {
//             this->data = data;
//             left = NULL;
//             right = NULL;
//         }
//     };

vector<int> PreOrder(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    Stack<TreeNode<int> *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        ans.push_back(root->data);
        if (root->right != NULL)
            st.push(root->right);
        if (root->left != NULL)
            st.push(root->left);
    }
    return ans
}