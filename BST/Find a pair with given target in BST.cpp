// } Driver Code Ends
/*Complete the function below
Node is as follows
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    bool checksum(struct Node *root,int target,unordered_set<int>&st){
        if(root==NULL)
        return false;
        
        if(checksum(root->left,target,st)==true)  // if the left value is true then it will directly return the true
        return true;
        
        if(st.find(target-root->data)!=st.end())
        return true;
        
        st.insert(root->data);
        return checksum(root->right,target,st);
        
        
    }
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
    unordered_set<int>st;
    return checksum(root,target,st);
    
    }
};
