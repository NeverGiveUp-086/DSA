/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        vector<int>res;
          
          if(root==NULL)
          return ans;

          queue<Node*>q;
          q.push(root);
          
          int n=0;
          while(q.size()>0){

                 n=q.size();
             for(int i=0;i<n;i++){
                 root=q.front();
                 q.pop();
                 res.push_back(root->val);

                //  if(root->left!=NULL)
                //  q.push(root->left);
                //  if(root->right!=NULL)
                //  q.push(root->right);
                  for (auto u : root->children)
                     q.push(u);
             }
              ans.push_back(res);
              res.clear();
          }

               return ans;
    }
};
