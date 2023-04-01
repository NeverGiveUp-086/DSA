
class Solution {
    
private:
    void dfs(int sr,int sc,int inicolor,vector<vector<int>>&ans,int color,int delrow[],int delcol[],vector<vector<int>>image){
        ans[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        
        for(int i=0;i<4;i++){
            int i1=sr+delrow[i];
            int j1=sc+delcol[i];
            if(i1>=0 && i1<n && j1>=0 && j1<m && image[i1][j1]==inicolor && ans[i1][j1]!=color){
                dfs(i1,j1,inicolor,ans,color,delrow,delcol,image);
            }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int inicolor=image[sr][sc];
       
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};

        dfs(sr,sc,inicolor,ans,color,delrow,delcol,image);
        return ans;
    }
};
