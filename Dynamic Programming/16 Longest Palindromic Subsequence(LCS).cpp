// GFG

class Solution{
  public:
  
   int solve(string x, string y){
       int n=x.size();
       int m=y.size();
       
       int dp[n+1][m+1];
       
       for(int i=0;i<n+1;i++){
           for(int j=0;j<m+1;j++){
               if(i==0 || j==0)
               dp[i][j]=0;
               
               else if(x[i-1]==y[j-1])
               dp[i][j]=1+dp[i-1][j-1];
               
               else
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
       }
       
       return dp[n][m];
   }
   
    int longestPalinSubseq(string a) {
        //code here
        string s=a;
        reverse(s.begin(),s.end());
        
        int lcslength=solve(a,s);
        
        return lcslength;
        
    }
};

