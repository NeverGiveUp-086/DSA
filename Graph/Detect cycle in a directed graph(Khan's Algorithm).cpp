
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int>indeg(v,0);
        for(int i=0;i<v;i++){
            for(auto x:adj[i])
            indeg[x]++;
        }
    
    
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indeg[i]==0)
        q.push(i);
    }
    int count=0;
    while(q.size()>0){
        int u=q.front();
        q.pop();
        count++;
        for(auto k:adj[u]){
            indeg[k]--;
            if(indeg[k]==0)
            q.push(k);
            
            
        }
    }
    return (count!=v);
}
    
};

