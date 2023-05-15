#Recursion 
// User function Template for C++

class Solution{
public:
  int solve(int a[],int i,int j){
      
      if(i>=j)
      return 0;
      int temp;
      int mn=INT_MAX;
      for(int k=i;k<=j-1;k++){
          temp=solve(a,i,k)+solve(a,k+1,j)+a[i-1]*a[k]*a[j];
          
          mn=min(mn,temp);
      }
      return mn;
  }
  
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        int ans=0;
        ans=solve(arr,1,n-1);
        
        return ans;
    }
};



//memset Bottom-Up

class Solution{
public:
  int dp[501][501];
  int solve(int a[],int i,int j){
      
      if(i>=j)
      return 0;
      
      if(dp[i][j]!=-1)
      return dp[i][j];
      
      int mn=INT_MAX;
      for(int k=i;k<=j-1;k++){
         int temp=solve(a,i,k)+solve(a,k+1,j)+a[i-1]*a[k]*a[j];
          
          mn=min(mn,temp);
      }
      return dp[i][j]=mn;
  }
  
    int matrixMultiplication(int n, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        ans=solve(arr,1,n-1);
        
        return ans;
    }
};

