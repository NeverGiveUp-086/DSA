class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n=nums.size();
      sort(nums.begin(),nums.end());
      map<int,int>mp;
      
      for(int i=0;i<n;i++){
        int x=sqrt(nums[i]);
        if(x*x==nums[i] && mp.find(x)!=mp.end())
          mp[nums[i]]=mp[x]+1;
          else
          mp[nums[i]]=1;
      }
      int ans=INT_MIN;
      for(auto x:mp){
        ans=max(ans,x.second);
      }
      if(ans==1)
        return -1;
      return ans;
    }
};
