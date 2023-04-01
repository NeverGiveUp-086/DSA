//gfg

class Solution {
//////

private:
    bool dfs(int node, vector<int> adj[], int parent, vector<bool> vis){
        vis[node] = true;
            for(auto it : adj[node]){
                if(vis[it] == false){
                    if(dfs(it, adj, node, vis)==true){
                        return true;
                    }
                }
                else if(it != parent){
                    return true;
                }
            }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            if(vis[i] == false)
                if(dfs(i, adj, -1, vis)==true) 
                    return true;
        }
        return false;
    }
};
 


