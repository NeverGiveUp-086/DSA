class Solution {
public:
int dp[1001][1001];

void lcs(string t1, string t2) {
        int n=t1.size();
        int m=t2.size();

        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++)
            if(i==0 || j==0)
            dp[i][j]=0;
        }
    
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){

            if(t1[i-1]==t2[j-1])
              dp[i][j]=1+dp[i-1][j-1];

              else
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
   }


    string solve(string a, string b){
      int n=a.size();
      int m=b.size();
       string s="";

       lcs(a,b);
      
      int i=n;
      int j=m;
      
      while(i>0 && j>0){
		if(a[i-1]==b[j-1]){
			s += a[i - 1];
			i--, j--;
		}
		else
		{
			if(dp[i][j-1]>dp[i-1][j]){
				s += b[j - 1];
				j--;
			}
			else{
				s += a[i - 1];
				i--;
			}
		}
	}
	
	while(i>0){
		s.push_back(a[i-1]);
		i--;
	}
	
	while(j>0){
		s.push_back(b[j-1]);
		j--;
	}

     reverse(s.begin(),s.end());
     return s;

    }
    string shortestCommonSupersequence(string s1, string s2) {
        string ans="";

        ans=solve(s1,s2);

        return ans;
    }
};
