// GFG
//TOPOLOGICAL sort using bfs 
class Solution{
    private:
    vector<int>toposort(vector<int>adj[],int k){
    //bool toposort(vector<int>adj[],int k){
        vector<int>indeg(k,0);
        vector<int>v;
        queue<int>q;
        
        for(int i=0;i<k;i++){
            for(auto x:adj[i])
            indeg[x]++;
        }
        
        for(int i=0;i<k;i++){
            if(indeg[i]==0)
            q.push(i);
        }
        while(q.size()>0){
            int u=q.front();
            q.pop();
            v.push_back(u);
            
            for(auto x:adj[u]){
                indeg[x]--;
                if(indeg[x]==0)
                q.push(x);
            }
        }
        return v;
    }
    
    public:
    string findOrder(string dict[], int n, int k) {
        //code here
      vector<int>adj[k];
      for(int i=0;i<n-1;i++){
          string s1=dict[i];
          string s2=dict[i+1];
          
          int len=min(s1.size(),s2.size());
          
          for(int j=0;j<len;j++){
              if(s1[j]!=s2[j]){
                  adj[s1[j]-'a'].push_back(s2[j]-'a');
              break;
              }
          }
      }
      
      vector<int>topo=toposort(adj,k);
      string ans="";
      
      for(auto it:topo){
          ans+=(it+'a');
      }
      return ans;
    }
};


Expected Time Complexity: O(N * |S| + K) , where |S| denotes maximum length.
Expected Space Compelxity: O(K)
