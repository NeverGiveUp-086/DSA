
class Solution {
  private:
    // Function to find the number of islands.
    void  bfs(int & i, int &j, vector<vector<int>>&vis,vector<vector<char>>&grid){
        vis[i][j]=1;
         int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int ni=q.front().first;
            int nj=q.front().second;
            q.pop();
          for(int x=-1;x<=1;x++){
              for(int y=-1;y<=1;y++){
                  int dx=x+ni;
                  int dy=y+nj;
                  if(dx>=0 && dy>=0 && dx<n && dy<m && vis[dx][dy]==0 && grid[dx][dy]=='1'){
                      vis[dx][dy]=1;
                      q.push({dx,dy});
                   
                  }
              }
          }
        }
    }
    public:
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                   bfs(i,j,vis,grid);
                   ans+=1;
                }
            }
        }
        return ans;
    }

};

