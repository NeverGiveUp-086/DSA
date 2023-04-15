class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board){
        int n=9;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){

                    for(char c='1';c<='9';c++){
                            if(isvalid(board,i,j,c)==true){
                             board[i][j]=c;

                            if(solve(board)==true)
                            return true;
                            else
                            board[i][j]='.';
                            }
                    }
                    return false;
                }
            }
        }
        return true;
    }




    bool isvalid(vector<vector<char>>& board,int row,int col,char c){
            
             for(int i=0;i<9;i++){
                 /// we check the row for that element 
                if(board[row][i]==c)
                return false;

                //we check column for that element
                if(board[i][col]==c)
                return false;

                //now we check for the grid
              if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
              return false;

             }
             return true;
    }

};
