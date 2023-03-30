
class Solution {
public:
	
	    // Code here
	    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }


    void revdfs(int node, vector<int> &vis, vector<int> rev[]) {
        vis[node] = 1;
        
        for (auto it : rev[node]) {
            if (!vis[it]) {
            revdfs(it, vis, rev);
            }
        }
    }

 

 //Function to find number of strongly connected components in the graph.

    int kosaraju(int V, vector<int> adj[])

    {

        //code here
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++){
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> rev[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                rev[it].push_back(i);
            }
        }
        
        int cnt = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                cnt++;
                revdfs(node, vis, rev);
            }
        }
        return cnt;
    }
    
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>adj[N];
	    for(int i=0;i<prerequisites.size();i++)
	    {
	        if(prerequisites[i].first==prerequisites[i].second)return false;
	        adj[prerequisites[i].first].push_back(prerequisites[i].second);
	    }
	    int count=kosaraju(N,adj);
	    if(count==N)return true;
	    return false;
	}
};
