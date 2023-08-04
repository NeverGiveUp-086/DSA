//gfg
//BFS
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    queue<int> q;
	    
	    vector<int> indegree(V,0);
      for(int i=0;i<V;i++){
          vector<int> data=adj[i];
          for(auto x: data){
              indegree[x]++;
              
          }
      }	 
      for(int i=0;i<V;i++){
          if(indegree[i]==0)
          q.push(i);
      }
      while(!q.empty()){
          int u=q.front();
          q.pop();
          ans.push_back(u);
          
          for(auto v:adj[u]){
              indegree[v]--;
              if(indegree[v]==0)
              q.push(v);
              
          }
      }
      return ans;
	}
};

//DFS
class Solution
{
    
    private:
    void solvedfs(int src,vector<int> adj[],stack<int>&st,vector<int>&visited){
        visited[src]=1;
        
      for(auto x:adj[src]){
          if(visited[x]==0)
          solvedfs(x,adj,st,visited);
      }
      st.push(src);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    vector<int>visited(v,0);
	    stack<int>st;
	    vector<int>ans;
	    for(int i=0;i<v;i++){
	        if(visited[i]==0){
	            solvedfs(i,adj,st,visited);
	        }
	    }
	    
	    while(st.size()>0){
	        int ele=st.top();
	        st.pop();
	        ans.push_back(ele);
	    }
	    return ans;
	}
};



// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)
