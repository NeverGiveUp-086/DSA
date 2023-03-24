/
class Solution {
  public:
    // Function to detect cycle in a directed graph.
   bool dfsrec(vector<int> adj[],int s,vector<bool>&visited,
        vector<bool>&recstack){
            visited[s]=true;
            recstack[s]=true;
            
            for(auto u:adj[s]){
                if(visited[u]==false && dfsrec(adj,u,visited,recstack))
                return true;
                
                else if(recstack[u]==true)
                return true;
            }
            recstack[s]=false;
            return false;
        }
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        
        vector<bool>visited(false,v);
        vector<bool>recstack(false,v);
        
        for(int i=0;i<v;i++){
            if(dfsrec(adj,i,visited,recstack)==true)
            return true;
        }
        return false;
    }
};

