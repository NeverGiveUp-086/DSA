//GFG
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<pair<int,int>>adj[n+1];
        
            for(auto x:edges){
                adj[x[0]].push_back({x[1],x[2]}); // {node,dist}
                adj[x[1]].push_back({x[0],x[2]});
            }
        
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[1]=0;
        pq.push({0,1});  //{node,dist}
        
        vector<int>parent(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        
        while(!pq.empty()){
            int topnode=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            
            for(auto it:adj[topnode]){
                int node=it.first;
                int adjW=it.second;
                
                if(dis+adjW<dist[node]){
                    dist[node]=dis+adjW;
                    pq.push({dist[node],node});
                    parent[node]=topnode;
                }
            }
        }
        if(dist[n]==INT_MAX)
        return {-1};
        // time complexity O(n)
        vector<int>path;
        int node=n;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
        
        // total time complexity will be O(Elogv)+O(n)
    }
};
