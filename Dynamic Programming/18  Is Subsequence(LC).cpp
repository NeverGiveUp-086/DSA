class Solution {
public:
    bool isSubsequence(string a, string b) {
      long long int n=a.size();
        long long int m=b.size();
        
        long long int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)
                dp[i][j]=0;
                
                else if(a[i-1]==b[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        // if(dp[n][m]==n)
        // return true;
        // else
        // return false;
        
        return dp[n][m]==n?true:false;  
    }
};
