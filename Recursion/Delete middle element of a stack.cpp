class Solution
{
    public:
    //Function to delete middle element of a stack.
    void solve(stack<int>&s,int k){
        //base condition
        //when the k becomes 1 then we pop that elemennt and 
        // return the function 
        if(k==1){
            s.pop();
            return;
        }
        //if k is not one then  we store the top element in the temp variable and 
        //and pop that top element and pass the stack again to solve function 
        
        int temp=s.top();
        s.pop();
        solve(s,k-1);
        // at last we again push the element which we have store in the 
        // temp variable
        s.push(temp);
        return;
    }
    void deleteMid(stack<int>&s, int n)
    {
        // code here.. 
        if(n==0)
        return;
        int k=n/2+1;
        // we pass the stack and the middle position of the stack
        solve(s,k);
        return;
    }
};

