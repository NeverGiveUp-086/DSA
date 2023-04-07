//GFG

class Solution {
    private:
    void dfs(int src,vector<int>&visited,stack<int>&st,vector<pair<int,int>>adj[]){
        visited[src]=1;
        
        // thsi dfs will run O(n+m) times
        for(auto x:adj[src]){
            int k=x.first;
            if(visited[k]==0){
                dfs(k,visited,st,adj);
            }
            
        }
        st.push(src);
    }
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[n];
        // first we will find the adjacency list with weight 
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        // then  we find the topological sort of the graph
        vector<int>visited(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(visited[i]==0)
            dfs(i,visited,st,adj);
        }
        
        vector<int>dist(n,1e9);
        dist[0]=0;
        
        while(!st.empty()){    //while loop will run O(n) times 
            int node=st.top();
            st.pop();
            
            for(auto it:adj[node]){   //this for loop will run O(m) times
                int v=it.first;
                int wt=it.second;
                
                if(dist[node]+wt<dist[v])
                dist[v]=dist[node]+wt;
            }
        }
        // this while loop will run O(n+m) times
       
        for(int i=0;i<n;i++){
            if(dist[i]==1e9)
            dist[i]=-1;
        }
        return dist;
    }
};

Expected Time Complexity: O(N+E), where N is the number of nodes and E is edges

Expected Space Complexity: O(N)
