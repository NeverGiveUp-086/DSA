public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        if(n==0) return 0;
        if(n<-1) return -1;
        int res=max(maximizeTheCuts(n-x,x,y,z),
        max(maximizeTheCuts(n-y,x,y,z),
        maximizeTheCuts(n-z,x,y,z)));
        return res+1;
    }
