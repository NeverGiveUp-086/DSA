class Solution{
public:
  bool isvalid(int node,int color[],bool graph[101][101],int n,int col){
        for(int k=0;k<n;k++){
            if(k!=node && graph[k][node]==1 && color[k]==col){
                return false;
            }
        }
        return true;
  }
   bool solve(int node,bool graph[101][101],int m,int n,int color[]){
       if(node==n)
       return true;
       
       for(int i=1;i<=m;i++){
           if(isvalid(node,color,graph,n,i)==true){
               color[node]=i;
               if(solve(node+1,graph,m,n,color)==true)
               return true;
               else
               color[node]=0;
           }
       }
       return false;
   }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n]={0};
        if(solve(0,graph,m,n,color)==true)
        return true;
        else 
        return false;
    }
};
