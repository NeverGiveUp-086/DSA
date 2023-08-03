class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int s){
        // code here
        vector<int>adj[n];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>dist(n,-1);
        dist[s]=0;
        queue<int>q;
        
        vector<bool>visited(n,false);
        
        q.push(s);
        visited[s]=true;
        
        while(q.size()>0){
            int u=q.front();
            q.pop();
            
            for(int k:adj[u]){
                if(visited[k]==false){
                    dist[k]=dist[u]+1;
                    visited[k]=true;
                    q.push(k);
                }
            }
        }
        return dist;
    }
};
