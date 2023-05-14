
class Solution
{
    public:
     int lcs(string t1, string t2) {
        int n=t1.size();
        int m=t2.size();

        int dp[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){

            if(i==0 || j==0)
            dp[i][j]=0;
        
            else if(t1[i-1]==t2[j-1])
              dp[i][j]=1+dp[i-1][j-1];

              else
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
    }
    
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string x, string y, int m, int n)
    {
        string s=x+y;
        int l=s.size();
        
        int commom=lcs(x,y);
        
        return l-commom;
    }
};

