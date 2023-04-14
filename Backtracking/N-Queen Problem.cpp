

class Solution{
public:
   bool issafe(int row,int col,vector<vector<bool>>&board,vector<vector<int>>&ans,int n){
       int x=row;
       int y=col;
       //row
       while(y>=0){
           if(board[x][y]==1)
           return false;
           y--;
       }
       
       //upper leftdiagonal
       x=row;
       y=col;
       while(y>=0 && x>=0){
           if(board[x][y]==1)
           return false;
           y--;
           x--;
       }
       
       x=row;
       y=col;
       while(y>=0 && x<n){
           if(board[x][y]==1)
           return false;
           y--;
           x++;
       }
       return true;
   }
   
   void solve(int col,vector<vector<int>>&ans,vector<vector<bool>>&board,int n){
       if(col==n){
           vector<int>temp;
           for(int col=0;col<n;col++){    //column
               for(int row=0;row<n;row++){   //row
               if(board[row][col]==1){
                   temp.push_back(row+1);
               }
               }
           }
           ans.push_back(temp);
           return;
       }
       
       for(int row=0;row<n;row++){
           if(issafe(row,col,board,ans,n)){
               board[row][col]=1;
               solve(col+1,ans,board,n);
               board[row][col]=0;   //backtrack
           }
       }
   }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>ans;
        vector<vector<bool>>board(n,vector<bool>(n,0));
        
        solve(0,ans,board,n);
        
        return ans;
    }
};

