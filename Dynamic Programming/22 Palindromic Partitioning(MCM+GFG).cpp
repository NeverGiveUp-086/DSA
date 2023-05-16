#Recursion
// User function Template for C++

class Solution{
public:
bool ispalindrome(string &s,int i ,int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
            i++;
            j--;
        }
    }
    return true;
}
int solve(string &s,int i ,int j){
    if(i>=j) 
    {return 0;}
   
    if(ispalindrome(s,i,j))
    {return 0;}
    int mn=INT_MAX;
  
    for(int k=i;k<j;k++){
        int temp=solve(s,i,k)+solve(s,k+1,j)+1;
        mn=min(temp,mn);
    }
    return mn;
}
    int palindromicPartition(string &s)
    {
      
        int i=0;
        int j=s.length()-1;
        return solve(s,i,j);
    }
};


#Memozation  Bottom-Up
class Solution{
public:
    int t[501][501]; 
  
    bool isPalin(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
              return false;
            }
            else{
              i++;j--;
            }
          
        }
        return true;
    }
    int solve(string &s,int i,int j)
    {
        if(i>=j)
            return 0;
        
       if(isPalin(s,i,j))
         return 0;
      
        if(t[i][j]!=-1)
        return t[i][j];
        
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int temp=solve(s,i,k)+solve(s,k+1,j)+1;
            ans=min(ans,temp);
        }
        return t[i][j]=ans;  
    }

    int palindromicPartition(string &str){
        memset(t,-1,sizeof(t));
        return solve(str,0,str.length()-1);     
    }

};


# DP Top-Down Optamized
class Solution{
public:
int dp[501][501];
bool ispalindrome(string &s,int i ,int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        else {
            i++;
            j--;
        }
    }
    return true;
}

int solve(string &s,int i ,int j){
    if(i>=j) 
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    if(ispalindrome(s,i,j))
    return 0;
    int left,right;
    
    int mn=INT_MAX;
    for(int k=i;k<j;k++){
         //int temp=solve(s,i,k)+solve(s,k+1,j)+1;
         //  we will also check for both the function in the table if they are solved then 
         // we don not need to solve it again 
         
         // we check both one by one 
        if(dp[i][k]!=-1)  // most opamized solution 
        left=dp[i][k];
        else
        left=solve(s,i,k);
        dp[i][k]=left;
        
        if(dp[k+1][j]!=-1)
        right=dp[k+1][j];
        else
        right=solve(s,k+1,j);
        dp[k+1][j]=right;
        
        int temp=1+left+right;
       
        mn=min(temp,mn);
    }
    return dp[i][j]=mn;
}

    int palindromicPartition(string &s)
    {
    
        memset(dp,-1,sizeof(dp));
        int i=0;
        int j=s.length()-1;
        return solve(s,i,j);
    }
};


