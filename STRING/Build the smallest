string buildLowestNumber(string num, int k)
{
    //code here.
    stack<char>st;
    int n=num.size();
    // Push the 1st element into the stack
    st.push(num[0]);
    
    for(int i=1;i<n;i++)
    {  
        // For each element check if it is greater less than 
    //the top element in the stack, if it is smaller than reduce 
    //the value of k by one and remove the top element from the stack 
        while(st.size()>0 && st.top()>num[i] && k>0){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    
    string ans="";
     // now we check if k is not zero then the means we have not remove all the element
     //now we reduce k and pop the element from the top because now bigger no is on the top
    while(k>0){
        st.pop();
        k--;
    }
    // when k becomes 0 then we add all the character int the ans string   
    while(st.size()>0){
        ans=st.top()+ans;
        st.pop();
    }
    
    // now we check for the 000 present in the front of the string 
    // ans="ANKUSH SINGH"   ans.substr(starting position from where we want string )
    // ans=ans.substr(7);
    
    for(int i=0;i<ans.size();i++){
        if(ans[i]!='0'){
            ans=ans.substr(i);
            return ans;
        }
    }
    return "0";
}
