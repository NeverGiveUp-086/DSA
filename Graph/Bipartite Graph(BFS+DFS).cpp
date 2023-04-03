//gfg

//BFS
class Solution {
    private:
    bool isbfs(int src,int v, vector<int>adj[],vector<int>&visited){
        visited[src]=0;
        queue<int>q;
	    q.push(src);
	    
	    
	    
	    while(q.size()>0){
	        int u=q.front();
	        q.pop();
	        
	        for(auto it:adj[u]){
	            if(visited[it]==-1){
	                visited[it]=!visited[u];
	                q.push(it);
	            }
	            else if(visited[it]==visited[u])
	            return false;
	        }
	    }
	    return true;
    }
public:
	bool isBipartite(int v, vector<int>adj[]){
	    // Code here
	    vector<int>visited(v,-1);
	    
	    for(int i=0;i<v;i++){
	        if(visited[i]==-1){
	            if(isbfs(i,v,adj,visited)==false)
	            return false;
	        }
	    }
	    return true;
	}

};


//DFS

class Solution {
    private:
    bool isdfs(int src,int lastcol,vector<int>adj[],vector<int>&visited){
        visited[src]=lastcol;
        
        for(auto it:adj[src]){
            if(visited[it]==-1){
                if(isdfs(it,!lastcol,adj,visited)==false)
                return false;
            }
            
            else if(visited[it]==lastcol)
                return false;
        }
        return true;
    }
public:
	bool isBipartite(int v, vector<int>adj[]){
	    // Code here
	    vector<int>visited(v,-1);
	    
	    for(int i=0;i<v;i++){
	        if(visited[i]==-1){
	            if(isdfs(i,0,adj,visited)==false)
	            return false;
	        }
	    }
	    return true;
	}

};


//
Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)
