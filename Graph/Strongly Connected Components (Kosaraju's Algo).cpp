/

class Solution
{
	private:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<vector<int>>& adj,vector<bool>&visited,stack<int>&st){
	    visited[node]=true;
	    for(auto it:adj[node]){
	        if(visited[it]==false)
	        dfs(it,adj,visited,st);
	    }
	    st.push(node);
	}
		void dfs2(int node,vector<int> adjT[],vector<bool>&visited){
	    visited[node]=true;
	    for(auto it:adjT[node]){
	        if(visited[it]==false)
	        dfs2(it,adjT,visited);
	    }
	}
	
	public:
    int kosaraju(int v, vector<vector<int>>& adj)
    {
        
        //step 1
        stack<int>st;
        vector<bool>visited(v,false);
        
        for(int i=0;i<v;i++){
            if(visited[i]==false){
                dfs(i,adj,visited,st);
                
            }
        }
        
        //step 2
        vector<int>adjT[v];
        for(int i=0;i<v;i++){
            visited[i]=false;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
            
        }
        
        
        int count=0;
        // step 3
        while(st.size()>0){
            int k=st.top();
            st.pop();
            if(visited[k]==false){
                count++;
                dfs2(k,adjT,visited);
            }
            
        }
        return count;
    }
};


// } Driver Code Ends
