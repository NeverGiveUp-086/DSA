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
     TreeNode* getsuccessor(TreeNode* root){
         root=root->right;
         while(root!=NULL && root->left!=NULL){
             root=root->left;
         }
         return root;
     }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        return root;

        if(root->val<key)   // when key is greater than root ka value the call the right node of the root
        root->right=deleteNode(root->right,key);

        else if(root->val>key)          // when key is less than root ka value the call the left node of the root
        root->left=deleteNode(root->left,key);
         
         else{
              if(root->left==NULL){  // when root ka left is null
                  TreeNode* temp=root->right;
                  delete root;
                  return temp;
              }

              else if(root->right==NULL){   // when root ka right is null
                  TreeNode* temp=root->left;
                  delete root;
                  return temp;
              }
           else{      //when both children are present of the root
               TreeNode* succ=getsuccessor(root);  // we find the inorder successor and replace the root node with the inorder successor 
               root->val=succ->val;
             root->right=deleteNode(root->right,succ->val);  // we call the function to delete the inorder successor   
           }

         }
         return root;
    }
};
