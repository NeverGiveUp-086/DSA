//gfg

//bfs

class Solution {
    private:
    void bfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& visited,vector<pair<int,int>>&v,int row0,int col0){
        visited[row][col]=1;
        v.push_back({row-row0,col-col0});
        
        queue<pair<int,int>>q;
        
        q.push({row,col});
        
        int n=grid.size();
        int m=grid[0].size();
        int delr[]={-1,0,1,0};
         int delc[]={0,1,0,-1};
         
         while(q.size()>0){
             
             int row=q.front().first;
             int col=q.front().second;
             q.pop();
             
             for(int i=0;i<4;i++){
               int newr=row+delr[i];
                int newc=col+delc[i];
             
            if(newr>=0 && newr<n && newc>=0 && newc<m && visited[newr][newc]==0 && grid[newr][newc]==1){
                visited[newr][newc]=1;
                q.push({newr,newc});
                v.push_back({newr-row0,newc-col0});
         }
        
             }
         }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        set<vector<pair<int,int>>>st;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]==1){
                    vector<pair<int,int>>v;
                    bfs(i,j,grid,visited,v,i,j);
                    st.insert(v);
                }
            }
        }
                return st.size();
    }
};



//dfs

class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& visited,vector<pair<int,int>>&v,int row0,int col0){
        visited[row][col]=1;
        v.push_back({row-row0,col-col0});
        
        int n=grid.size();
        int m=grid[0].size();
        int delr[]={-1,0,1,0};
         int delc[]={0,1,0,-1};
         
         for(int i=0;i<4;i++){
             int newr=row+delr[i];
             int newc=col+delc[i];
             
             if(newr>=0 && newr<n && newc>=0 && newc<m && visited[newr][newc]==0 && grid[newr][newc]==1)
             dfs(newr,newc,grid,visited,v,row0,col0);
             
         }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        set<vector<pair<int,int>>>st;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){                      // loop time complexity O(n*m)
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]==1){
                    vector<pair<int,int>>v;
                    dfs(i,j,grid,visited,v,i,j);  //dfs time complexity O(n*m*4)
                    st.insert(v);
                }
            }
        }
                return st.size();
    }
};


// over all time complexity O(n*m)+log(set(n*m))+O(n*m*4)

