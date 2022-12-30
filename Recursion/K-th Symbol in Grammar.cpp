class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 && k==1)
        return 0;
        // here we find the length because the length is the power of two
        // so we find the length by using 2^(n-1) formula
        int length=pow(2,n-1);
        int mid=length/2;
       
       //everey next row has double element of the previous row;
       //every next row element are equal to the length of  previous row element 
       // then element are the compelemt of the k-mid element
        if(k<=mid)
        return kthGrammar(n-1,k);
        else
        return !kthGrammar(n-1,k-mid);
    }
};
