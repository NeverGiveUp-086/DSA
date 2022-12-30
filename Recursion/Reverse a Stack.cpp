class Solution{
public:
    void insert(stack<int> &st,int temp){
        if(st.size()==0){
            st.push(temp);
            return;
        }
        int val=st.top();
        st.pop();
        insert(st,temp);
        st.push(val);
        return;
        
    } 
    void Reverse(stack<int> &st){
        if(st.size()==1)
        return;
        int top=st.top();
        st.pop();
        Reverse(st);
        insert(st,top);
        return;
    }
};
