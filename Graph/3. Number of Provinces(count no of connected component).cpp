// no of island or no of connected graph

// 1  bfs using  adjacency matrix 
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



// 2 bfs using adjacency list

class Solution {
  public:
  void bfs(vector<int>adj[],int s,vector<bool>&visited){
        queue<int>q;
        q.push(s);
        visited[s]=true;
        
        while(q.size()>0){
            int u=q.front();
            q.pop();
            
            //ans.push_back(u);
            
            for(int v:adj[u]){
                if(visited[v]==false){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int v) {
        // code here
        vector<int>adjl[v];
        for(int i=0;i<v;i++){    // matrix to list 
            for(int j=0;j<adj[i].size();j++){
               if(adj[i][j]==1){
                   adjl[i].push_back(j);
               }
            }
        }
        vector<bool>visited(v,false);
        int count=0;
        
        for(int i=0;i<v;i++){
            if(visited[i]==false){
                bfs(adjl,i,visited);
                count++;
            }
            
        }
        return count;
        
    }
};


// 3 dfs using adjacency matrix 
class Solution {
  public:
  void dfs(vector<vector<int>> &adj,int s,vector<int>&visited){
      visited[s]=true;
     
      
          for(int i=0;i<adj[s].size();i++){
              if(visited[i]==false && adj[s][i]==1){
                  visited[i]=true;
                 dfs(adj,i,visited);
              }
          }
      }
  
    int numProvinces(vector<vector<int>> adj, int v){
        // code here
        vector<int>visited(v,false);
        int count=0;
        
        for(int i=0;i<v;i++)
            if(visited[i]==false){
            dfs(adj,i,visited);
            count++;
        }
        return count;
    }
};


// 4 dfs using adjacency list 

class Solution {
  public:
  void dfs(vector<int>adj[],int s,vector<bool>&visited){
      
        visited[s]=true;
            
            for(int v:adj[s]){
                if(visited[v]==false){
                    visited[v]=true;
                    dfs(adj,v,visited);
                }
            }
        }
    
    int numProvinces(vector<vector<int>> adj, int v) {
        // code here
        vector<int>adjl[v]; 
        for(int i=0;i<v;i++){     // matrix to list 
            for(int j=0;j<adj[i].size();j++){
               if(adj[i][j]==1){
                   adjl[i].push_back(j);
               }
            }
        }
        vector<bool>visited(v,false);
        int count=0;
        
        for(int i=0;i<v;i++){
            if(visited[i]==false){
                dfs(adjl,i,visited);
                count++;
            }
            
        }
        return count;
        
    }
};


