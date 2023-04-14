
class Solution{
    public:
    
    bool issafe(int i,int j,vector<vector<int>>&visited,vector<vector<int>> &m,int n){
        if(i>=0 && i<n && j>=0 && j<n && visited[i][j]==0 && m[i][j]==1)
        return true;
        else
        return false;
    }
    bool ispath(int x,int y,vector<string>&ans,vector<vector<int>>&visited,string path,int n,vector<vector<int>> &m){
        
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return true;
        }
        
        visited[x][y]=1;
          
          //DOWN
          if(issafe( x+1, y,visited ,m,n)==true)
          ispath(x+1,y,ans,visited,path+'D',n,m);
          
          //left
          if(issafe( x, y-1,visited ,m,n)==true)
          ispath(x,y-1,ans,visited,path+'L',n,m);
          
          //right
          if(issafe( x, y+1,visited ,m,n)==true)
          ispath(x,y+1,ans,visited,path+'R',n,m);
          
          //UP
          if(issafe( x-1,y,visited ,m,n)==true)
          ispath(x-1,y,ans,visited,path+'U',n,m);
          
        visited[x][y]=0;
    }
    
     
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes 
        vector<string>ans;
        vector<vector<int>>visited(n,vector<int>(n,0));
         string path="";
        if(m[0][0]==0)
        return ans;
        
        // if(ispath(0,0,ans,visited,path,n,m)==true)
        ispath(0,0,ans,visited,path,n,m);
        return ans;
        // else
        // return ans;
    }
};

    


