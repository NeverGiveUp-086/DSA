
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<bool>visited(v,false);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        vector<int>ans;
        while(q.size()>0){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(auto v:adj[u]){
                if(visited[v]==false){
                visited[v]=true;
                q.push(v);
                }
            }
        }
        return ans;
    }
};

