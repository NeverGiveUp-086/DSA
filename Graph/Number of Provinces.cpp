// no of island or no of connected graph


class Solution {
  public:
  void bfs(vector<vector<int>> adj, int s,bool visited[]){
      
      queue<int>q;
      visited[s]=true;
      q.push(s);
      while(q.size()>0){
          int u=q.front();
          q.pop();
          for(int i=0;i<adj[u].size();i++){
              if(visited[i]==false && adj[u][i]==1){
                  visited[i]=true;
                  q.push(i);
              }
          }
      }
      
  }
    int numProvinces(vector<vector<int>> adj, int v) {
        // code here
        bool visited[v];
        for(int i=0;i<v;i++)
        visited[i]=false;
        int count=0;
        
        for(int i=0;i<v;i++)
            if(visited[i]==false){
            bfs(adj,i,visited);
            count++;
        }
        return count;
    }
};

