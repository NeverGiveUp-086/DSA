
class Solution{
		
	public:
	 int  solve(string a, string b){
	     int n=a.length();
	     int m=b.length();
	     
	     int dp[n+1][m+1];
	     for(int i=0;i<n+1;i++){
	         for(int j=0;j<m+1;j++){
	             
	             if(i==0 || j==0 )
	             dp[i][j]=0;
	             
	             else if(a[i-1]==b[j-1]){
	                 dp[i][j]=1+dp[i-1][j-1];
	             }
	             
	             else{
	                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	             }
	             
	         }
	     }
	     
	     return dp[n][m];
	     
	 }
	
	int minOperations(string s1, string s2) 
	{ 
	    // Your code goes here
	    int  lcslength=solve(s1,s2);
	    
	    int l1=s1.size();
	    int l2=s2.size();
	    
	    
	    int ans=0;
	    ans+=(l1-lcslength)+(l2-lcslength);
	    
	    return ans;
	} 
};
