1 Recursion
// User function template for C++

class Solution {
  public:
    int search(int arr[],int low,int high,int k){
        if(low>high)
        return -1;
        
        int mid=(low+high)/2;
        if(arr[mid]==k) 
        return mid;
        else if(arr[mid]>k)
        return search(arr,low,mid-1,k);
        else if(arr[mid]<k)
        return search(arr,mid+1,high,k);
    }
    int binarysearch(int arr[], int n, int k) {
        // code here
        return search(arr,0,n-1,k);
    }
};


2. Iterative
// User function template for C++

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        int low=0;
        int high=n-1;
       // int mid=(low+high)/2;
        while(low<=high){
             int mid=(low+high)/2;
            if(arr[mid]==k)
            return mid;
            else if(arr[mid]>k)
                 high=mid-1;
                 else if(arr[mid]<k)
                 low=mid+1;
        }
        return -1;
    }
};
