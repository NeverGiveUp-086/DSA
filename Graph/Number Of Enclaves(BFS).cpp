//gfg

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        
    
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && (i==0 || i==n-1 || j==0 || j==m-1)){
                     visited[i][j]=1;
                     q.push({i,j});
                }
            }
        }
        
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
                }
            }
            
        }
        
        
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]==1)
                count++;
            }
        }
        return count;
    }
};


