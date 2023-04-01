//gfg
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>ans(n,vector<int>(m,0));
	    vector<vector<int>>visited(n,vector<int>(m,0));
	   
	    queue<pair<pair<int,int>,int>>q;  //({{i,j},dist});
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                visited[i][j]=1;
	            }
	        }
	    }
	    
	    int delr[]={-1,0,1,0};
	    int delc[]={0,1,0,-1};
	       while(q.size()>0){
	        int row=q.front().first.first;
	        int col=q.front().first.second;
	        int dist=q.front().second;
	        q.pop();
	        ans[row][col]=dist;
	        
	        
	        for(int i=0;i<4;i++){
	            int newr=row+delr[i];
	            int newc=col+delc[i];
	            
	            if(newr>=0 && newr<n && newc>=0 && newc<m && visited[newr][newc]==0){
	                visited[newr][newc]=1;
	            q.push({{newr,newc},dist+1});
	            }
	        }
	       
	     }
	     return ans;
	}
};


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
