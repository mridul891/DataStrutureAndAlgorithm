#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node()
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;

    }
};
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.

    vector<int> topView(Node *root)
    {
        //Your code here
        vector <int>ans;
        if ( root == NULL) return ans ;
   
      map <int , int>mpp;
      queue<pair < Node * , int> >q;
      q.push({root ,0});
      while ( !q.empty()){
          vector<int>res;
          auto it = q.front();
          q.pop(); 
          Node * node = it.first;
            int level = it.second;
            
          if(mpp.find(level) == mpp.end()) mpp[level] = node->data;
            
        
        
        if (node ->left) q.push({node->left , level-1});
        if (node ->right) q.push({node->right , level+1});
      }
      
      for(auto  i : mpp) {
              ans.push_back(i.second);
      }
    return ans;
    }

};
