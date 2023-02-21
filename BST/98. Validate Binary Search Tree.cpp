// TC=O(n)
// auxiliary space O(height)

class Solution {
public:
  long long  prevNode=LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
        return true;

        if(isValidBST(root->left)==false)
        return false;
             
             if(root->val<=prevNode)
             return false;

             prevNode=root->val;

             return isValidBST(root->right);
    }
};

// TC=O(n)
// space copmlexity=O(1)

class Solution {
public:
     bool solve(TreeNode* root,long mn,long mx){
         if(root==NULL)
         return true;

         return (root->val>mn && root->val<mx &&  solve(root->left,mn,root->val) && solve(root->right,root->val,mx));
     }
    bool isValidBST(TreeNode* root) {
      bool ans=solve(root,LONG_MIN,LONG_MAX);
           return ans;
    }
};
