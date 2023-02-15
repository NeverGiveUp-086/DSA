/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int ans=0;

     void inorder(TreeNode* root){
           if(root==NULL)
           return;

           inorder(root->right);
           ans+=root->val;
           root->val=ans;
           inorder(root->left);

     }
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        return root;

    }
};
