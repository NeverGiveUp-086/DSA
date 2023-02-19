int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    // Your code here
    int res=-1;
    while(root!=NULL){
        if(root->data==input)
        return input;
        
        else if(root->data<input){
            root=root->right;
        }
        else{
            res=root->data;
            root=root->left;
        }
        
    }
    return res;
}
