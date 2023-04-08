//GFG

// USING PERIORITY QUEUE
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Code here
        
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(v,INT_MAX);
        pq.push({0,s});   // {dist,source}
        dist[s]=0;
        
        while(pq.size()>0){
            int duri=pq.top().first;
            int nodetop=pq.top().second;
            pq.pop();
            
            for(auto it:adj[nodetop]){
                    int node=it[0];
                    int dis=it[1];
                    
                    
                    if(duri+dis<dist[node]){
                        dist[node]=duri+dis;
                        pq.push({dist[node],node});
                    }
            }
        }
        return dist;
    }
};


//USING SET
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Code here
        set<pair<int,int>>st;
        vector<int>dist(v,INT_MAX);
        st.insert({0,s});  //{dist,node}
        dist[s]=0;
        
        while(!st.empty()){
            auto it=*(st.begin());
            int nodetop=it.second;
            int dis=it.first;
            
            st.erase(it);
            
            for(auto it:adj[nodetop]){
                int node=it[0];
                int wt=it[1];
                
                if(dis+wt<dist[node]){
                    dist[node]=dis+wt;
                    
                    st.insert({dist[node],node});
                }
            }
        }
        return dist;
    }
};


Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V2).


