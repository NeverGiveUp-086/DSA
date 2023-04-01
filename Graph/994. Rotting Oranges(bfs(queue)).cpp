//using  bfs queue 

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                q.push({0,{i,j}});
            }
        }

        int delr[]={-1,0,+1,0};
        int delc[]={0,+1,0,-1};

        int ans=0;
        while(q.size()>0){
            int row=q.front().second.first;
            int col=q.front().second.second;
             int t=q.front().first;
               q.pop();

             for(int i=0;i<4;i++){
                int newr=row+delr[i];
                int newc=col+delc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1){
                grid[newr][newc]=2;

                q.push({t+1,{newr,newc}});

                ans=max(ans,t+1);
                }
             }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                return -1;
            }
        }
        return ans;
    }
};


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
