class Solution {
  public:
        struct Node* prev=NULL;
     struct  Node* first=NULL;
     struct  Node* second=NULL;
    void inorder( struct Node* root )
    {
        // add code here.
        if(root==NULL)
        return;
       inorder(root->left);
         if(prev!=NULL && root->data<prev->data){
             if(first==NULL)
                 first=prev;

             second=root;
         }
          prev=root;
        inorder(root->right);
        
    }
  
  
    void correctBST( struct Node* root )
    {
        inorder(root);
        swap(first->data,second->data);
    }
};


