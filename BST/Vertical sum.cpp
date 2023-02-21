class Solution{
  public:
    void inorder(Node* root,int hd,map<int,int>&mp){
        if(root==NULL)
        return;
        inorder(root->left,hd-1,mp);
        mp[hd]+=root->data;              // time complexity O(nlog(hd))
        inorder(root->right,hd+1,mp);
    }
    vector <int> verticalSum(Node *root) {
        // add code here.
        map<int,int>mp;
        vector<int>v;
        inorder(root,0,mp);  // time complexity O(hd)
        for(auto &x:mp){
            v.push_back(x.second);
        }
        return v;
    }
};

//time copmlexity O(nlog(hd)+hd)
