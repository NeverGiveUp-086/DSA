//Recursion 

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int e, int f) 
    {
        // your code here
        if(e==1)
        return f;
        
        if(f<=1)
        return f;
        
        int mn=INT_MAX;
        
        for(int k=1;k<=f;k++){
            int temp=1+eggDrop(e-1,f-1)+eggDrop(e,f-k);
            mn=min(mn,temp);
        }
        return mn;
    }
};


// Memoization
class Solution
{
    
    int dp[201][201];
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int e, int f) 
    {
        
        memset(dp,-1,sizeof(dp));
        
        if(e==1)
        return f;
        
        if(f<=1)
        return f;
        
        if(dp[e][f]!=-1)
        return dp[e][f];
        
        int mn=INT_MAX;
        for(int k=1;k<=f;k++){
            
            int temp=1+max(eggDrop(e-1,k-1),eggDrop(e,f-k));
            mn=min(mn,temp);
        }
        return dp[e][f]=mn;
    }
};


// Memoization -> optimization
class Solution
{
    int dp[201][201];
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int e, int f) 
    {
        
        memset(dp,-1,sizeof(dp));
        
        if(e==1)
        return f;
        
        if(f==0 || f==1)
        return f;
        
        if(dp[e][f]!=-1)
        return dp[e][f];
        
        int mn=INT_MAX;
        int eggbreak,eggnotbreak;
        
        for(int k=1;k<=f;k++){
            
            if(dp[e-1][k-1]!=-1)
               eggbreak=dp[e-1][k-1];
               
               else{
                   eggbreak=eggDrop(e-1,k-1);
                   dp[e-1][k-1]=eggbreak;
               }
               
               
               if(dp[e][f-k]!=-1)
               eggnotbreak=dp[e][f-k];
               
               else{
                   eggnotbreak=eggDrop(e,f-k);
                   dp[e][f-k]=eggnotbreak;
               }
               
            int temp=1+max(eggbreak,eggnotbreak);
            mn=min(mn,temp);
        }
        return dp[e][f]=mn;
    }
};

