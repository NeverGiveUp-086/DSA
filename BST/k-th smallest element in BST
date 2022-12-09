class Solution {
  public:
   void inorder(Node* root,vector<int>&v){
       if(root==NULL)
       return;
       inorder(root->left,v);
       v.push_back(root->data);
       inorder(root->right,v);
   }
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int k) {
        // add code here.
        vector<int>vec;
        inorder(root,vec);
        int ans=-1;
        sort(vec.begin(),vec.end());
        if(vec.size()>=k)
        return vec[k-1];
        return ans;
        
    }
};

// solution 2 
class Solution {
  public:
  void fun(Node* root,int &k ,int &ans){
      if(root==NULL) return;
      fun(root->left,k,ans);
        k--;
      if(k==0)
      ans=root->data;
      fun(root->right,k,ans);
  }
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int k) {
        // add code here.
        int ans=-1;
        fun(root,k,ans);
        return ans;
    }
};
