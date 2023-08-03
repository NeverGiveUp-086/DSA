//gfg
// bfs solution
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


 // dfs solution
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
 
