//GFG

class Solution
{
  public:
    vector<int>findOrder(int n, int m, vector<vector<int>> arr) 
    {
        //code here
        vector<int>indeg(n,0);
        vector<int>ans;
        vector<int>adj[n];
           
        for(int i=0;i<m;i++){
            adj[arr[i][1]].push_back(arr[i][0]);
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            for(auto x:adj[i])
            indeg[x]++;
        }
        
        for(int i=0;i<n;i++){
            if(indeg[i]==0)
            q.push(i);
        }
        
        while(q.size()>0){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            
            for(auto k:adj[u]){
                indeg[k]--;
                if(indeg[k]==0)
                q.push(k);
            }
        }
        if(ans.size()==n)
            return ans;
        
        
        return {};
        
    }
};


Expected Time Complexity: O(n+m).
Expected Auxiliary Space: O(n+m).
