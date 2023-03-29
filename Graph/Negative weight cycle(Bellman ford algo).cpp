
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>dist(n,1e8);
	    dist[0]=0;
	    
	    for(int i=0;i<n-1;i++){
	        for(auto it:edges){
	            
	        int u=it[0];
	        int v=it[1];
	        int w=it[2];
	        
	        if(dist[v]>dist[u]+w){
	            dist[v]=dist[u]+w;
	        }
	        
	        }
	    }
	    for(auto it:edges){
	        int u=it[0];
	        int v=it[1];
	        int w=it[2];
	        
	        
	        if(dist[v]>dist[u]+w){
	            return 1;
	        }
	    }
	    return 0;
	}
};
