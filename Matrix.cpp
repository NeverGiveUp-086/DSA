class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size();
        int n=mat[0].size();

        if(n*m!=r*c)
        return mat;

        vector<vector<int>>res(r,vector<int>(c));
        int row=0;
        int col=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[row][col]=mat[i][j];
                   col++;
                   if(col==c){
                       col=0;
                       row++;
                   }
            }
        }
     return res;

        
    }
};
