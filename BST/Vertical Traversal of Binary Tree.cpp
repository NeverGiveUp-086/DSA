class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int,vector<int>>mp;
        queue<pair<Node*,int>>q;
            
            q.push({root,0});

            while(q.size()>0){
                auto p=q.front();
                Node* curr=p.first;
                int hd=p.second;
                mp[hd].push_back(curr->data);
                q.pop();

                if(curr->left!=NULL)
                q.push({curr->left,hd-1});
                if(curr->right!=NULL)
                q.push({curr->right,hd+1});
            }
            vector<int>ans;
            for(auto i:mp){
                for(auto j:i.second){
                    ans.push_back(j);
                }
            }
            return ans;
    }
};
