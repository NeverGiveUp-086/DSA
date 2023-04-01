//gfg
class Solution {
    
    private:
    bool bfs(vector<int> adj[],vector<bool>&visited,int src,int parent){
        visited[src]=true;
        queue<pair<int,int>>q;  // ({node,parent});
        
        q.push({src,parent});
        
        while(q.size()>0){
            int node=q.front().first;
            int parent=q.front().second;
            
            q.pop();
            
            for(auto it:adj[node]){
                if(visited[it]==false){
                    visited[it]=true;
                q.push({it,node});
                }
                else if(parent!=it)
                return true;
            }
            
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<bool>visited(v,false);
        
        
        for(int i=0;i<v;i++){
            if(visited[i]==false)
                if(bfs(adj,visited,i,-1)==true)
                return true;
            }
        return false;
    }
};
