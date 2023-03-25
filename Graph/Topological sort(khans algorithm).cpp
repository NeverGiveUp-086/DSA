
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    
	    vector<int>indegree(v,0);
	    
	    for(int i=0;i<v;i++){
	        for(auto x:adj[i]){
	            indegree[x]++;
	        }
	    }
	    vector<int>ans;
	    queue<int>q;
	    for(int i=0;i<v;i++){
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    
	    while(q.size()>0){
	        int u=q.front();
	        q.pop();
	        ans.push_back(u);
	        
	        for(auto i:adj[u]){
	            indegree[i]--;
	            if(indegree[i]==0)
	            q.push(i);
	        }
	    }
	    return ans;
	}
};



