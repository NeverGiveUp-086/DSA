//gfg

class Solution{
    private:
    
    void dfs(int row,int col,vector<vector<char>>&mat,vector<vector<int>>&visited,int delr[],int delc[]){
        visited[row][col]=1;
        
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<4;i++){
            int newr=row+delr[i];
            int newc=col+delc[i];
            
            if(newr>=0 && newr<n && newc>=0 && newc<m && visited[newr][newc]==0 && mat[newr][newc]=='O')
            dfs(newr,newc,mat,visited,delr,delc);
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
         vector<vector<int>>visited(n,vector<int>(m,0));
         
         int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        //traverse the top row row and bottom column
        for(int j=0;j<m;j++){
            if(visited[0][j]==0 && mat[0][j]=='O')
            dfs(0,j,mat,visited,delr,delc);
            
            if(visited[n-1][j]==0 && mat[n-1][j]=='O')
            dfs(n-1,j,mat,visited,delr,delc);
        }
        
        
        //traverse the left row row and right column
        for(int i=0;i<n;i++){
            if(visited[i][0]==0 && mat[i][0]=='O')
            dfs(i,0,mat,visited,delr,delc);
            
            if(visited[i][m-1]==0 && mat[i][m-1]=='O')
            dfs(i,m-1,mat,visited,delr,delc);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && mat[i][j]=='O')
                mat[i][j]='X';
            }
        }
        
        
         return mat;
    }
};

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
