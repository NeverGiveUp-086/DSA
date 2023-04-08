//GFG
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        queue<pair<int,pair<int,int>>>q; //{dist,{sourcenode}}
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[source.first][source.second]=0;
        q.push({0,{source.first,source.second}});
        
        if(source.first==destination.first && source.second==destination.second)
                     return 0;
                     
        int delc[]={0,+1,0,-1};
        int delr[]={-1,0,+1,0};
        
        while(!q.empty()){
            int dis=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int newr=r+delr[i];
                int newc=c+delc[i];
                
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && dis+1<dist[newr][newc]){
                     dist[newr][newc]=dis+1;
                     
                     if(newr==destination.first && newc==destination.second)
                     return dist[newr][newc];
                     q.push({dis+1,{newr,newc}});
                 }
            }
        }
        return -1;
    }
};
