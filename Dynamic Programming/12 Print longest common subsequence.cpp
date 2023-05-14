#include<algorithm>
#include <iostream>
#include <string>

using namespace std;
static int  dp[101][101];

 void lcs(string t1, string t2) {
        int n=t1.size();
        int m=t2.size();

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
    }

string solve(string &a,string &b){
        
    string ans="";
    int m=a.size();
    int n=b.size();
        lcs(a,b);
    
        int i=m;
        int j=n;
     
        while(i>0 && j>0){
            if(a[i-1]==b[j-1]){
              ans.push_back(a[i-1]);
              i--;
              j--;
            }
            else{
               if(dp[i][j-1]>dp[i-1][j])
               j--;
               else
               i--;
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
}


int main(){
    string s1="abac";
    string s2="cab";
     

    string res=solve(s1,s2);

    cout<< "Longest common subsequence is : "<<res;
}
