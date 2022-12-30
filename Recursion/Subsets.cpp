//ALGORITHM
 /*
 1.Create a recursive function that takes the following parameters, 
 input array, the current index, the output array, or current subset, 
 if all the subsets need to be stored then a vector of the array is needed 
 if the subsets need to be printed only then this space can be ignored.
 
 2.First, print the subset (output array) that has been sent to the function
 and then run a for loop starting from the ‘index’ to n-1 where n is the size 
 of the input array. We use a loop to demonstrate that we have exactly n number
 of choices to choose from when adding the first element to our new array.
 
 3.Inside the loop, we call the function for the next index after inserting 
 that particular index and then in the next call, we again have (n-1) choices
 to choose from and so it goes. 
 
 4.Whenever a call is made for the last index of the array : in that function
 call, the loop is not run as the condition i<A.size() is not fulfilled and
 hence, we backtrack to the last recursion call and call the function for the
 next index after removing the element at that current index.
*/
class Solution
{
    public:
    void findsubset(vector<int>& A,vector<vector<int>>&res,vector<int>&subset,int index){
        res.push_back(subset);
        
    // Loop to choose from different elements present
    // after the current index 'index'
        for(int i=index;i<A.size();i++){
            
             // include the A[i] in subset.
            subset.push_back(A[i]);
            
            // move onto the next element.
            findsubset(A,res,subset,i+1);
            
        // exclude the A[i] from subset and triggers
        // backtracking.
            subset.pop_back();
        }
        return;
    }
    
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<int>subset;
        vector<vector<int>>res;
        
        // keeps track of current element in vector A
      // and the number of elements present in the array subset
        int index=0;
        findsubset(A,res,subset,index);
        sort(res.begin(),res.end());
        return res;
    }
};

