class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int>s;
        
        for(auto x:tokens)
        {
            if(x=="+" || x=="-" || x=="*" || x=="/")
            {
                long long int n=s.top(); s.pop();
                long long  int m=s.top(); s.pop();

                if(x=="+")
                s.push(n+m);

                if(x=="-")
                s.push(m-n);

                if(x=="*")
                s.push(m*n);

                if(x=="/")
                s.push(m/n);
            }
            else{
             s.push(stoi(x));
            }
            
           
        }
        return s.top();

    }
};
