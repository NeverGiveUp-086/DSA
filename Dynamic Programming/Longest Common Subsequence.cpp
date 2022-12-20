#recursion 
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // we will check the base condition if any one of them length is zero then return 0 
        if(x==0 || y==0)
        return 0;
        
        //then we check the last element of both the string if they are same then  we count 1 and again 
        //call the function by decreasiing the length of both the string  
        if(s1[x-1]==s2[y-1])
        return 1+lcs(x-1,y-1,s1,s2);
        else 
        // if the last element of both the string are not same then we take the max of both string 
        //first we decsease the length of s1 by one then call the function and again then we call the 
        // function by decreasing the length of s2 by 1 and take the full length of s1;
        return max(lcs(x-1,y,s1,s2),lcs(x,y-1,s1,s2));
    }
};

//Dynamic programming 

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int dp[x+1][y+1];
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                if(i==0 || j==0)
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[x][y];
    }
};
