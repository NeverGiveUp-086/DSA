//inorder recursion 
// time complexity O(n)
class Solution {
public:
  int ans;
  int count=0;
    void solve(TreeNode* root,int k){
        if(root==NULL)
        return;

        solve(root->left,k);
      count++;
        if(count==k){
            ans=root->val;
            return;
        }
        solve(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        solve(root,k);
        return ans;
    }
};




//iterative solution 
//time complexity O(n)
// space complexity O(1)

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>st;
        TreeNode* curr=root;

        while(curr || st.size()>0){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            k--;
            if(k==0)
            return curr->val;
            st.pop();
            curr=curr->right;
        }
        return 0;
    }
};
