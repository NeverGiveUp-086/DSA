
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfsrecursive(int s,vector<int>adj[],vector<int>&ans,vector<bool>&visited){
        visited[s]=true;
        
        ans.push_back(s);
        
        for(auto u:adj[s]){
            if(visited[u]==false)
            dfsrecursive(u,adj,ans,visited);
        }
    }
    
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<bool>visited(v,false);
        vector<int>ans;
        
        for(int i=0;i<v;i++){
            if(visited[i]==false)
            dfsrecursive(i,adj,ans,visited);
        }
        
        return ans;
    }
};

