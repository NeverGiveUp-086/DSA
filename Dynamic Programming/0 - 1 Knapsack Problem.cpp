
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[n+1][w+1];
       for(int i=0;i<n+1;i++){
           for(int j=0;j<w+1;j++){
               if(i==0 || j==0)
               dp[i][j]=0;
           }
       }
       for(int i=1;i<n+1;i++){
           for(int j=1;j<w+1;j++){
               if(wt[i-1]<=j)
                   dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
               else 
                   dp[i][j]=dp[i-1][j];
           }
       }
       return dp[n][w];
    }
};


