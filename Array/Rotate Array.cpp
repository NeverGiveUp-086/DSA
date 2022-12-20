Approach 1 using temporary array

void rotateArr(int arr[], int d, int n){
        // code here
        
        while(d>n){
        d=d-n;
         }
        int temp[n];
        int j=0;
        for(int i=d;i<n;i++){
            temp[j]=arr[i];
            j++;
        }
        for(int i=0;i<d;i++){
            temp[j]=arr[i];
            j++;
        }
        for(int i=0;i<n;i++){
            arr[i]=temp[i];
        }
    }
    
    
    Approach 2 using queue
   void rotateArr(int arr[], int d, int n){
        // code here
        if(d>n){
            d=d-(d/n)*n;
        }
        queue<int>q;
        for(int i=d;i<n;i++){
            q.push(arr[i]);
        }
        for(int i=0;i<d;i++){
            q.push(arr[i]);
        }
        for(int i=0;i<n;i++){
            arr[i]=q.front();
            q.pop();
        }
      
    }
    
