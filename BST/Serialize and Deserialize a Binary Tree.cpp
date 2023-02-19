class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    const  int empty=-1;
    void solve(Node* root,vector<int>&v){
        if(root==NULL){
            v.push_back(empty);
            return;
        } 
        v.push_back(root->data);
        solve(root->left,v);
        solve(root->right,v);
    }
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int>v;
        solve(root,v);
        return v;
        
    }
    
    //Function to deserialize a list and construct the tree.
    //const  int empty=-1;
    int index=0;
    Node * deSerialize(vector<int> &a)
    {
       //Your code here
       if(index==a.size())
       return NULL;
       
       int val=a[index];
       index++;
       if(val==empty)
       return NULL;
       
       Node* root=new Node(val);
       root->left=deSerialize(a);
        root->right=deSerialize(a);
        return root;
    }
};
