//GFG

class Solution {
public:
    int wordLadderLength(string startWord, string target, vector<string>& wordList) {
        // Code here
        queue<pair<string,int>>q;
        q.push({startWord,1});
        
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(startWord);
        
        while(!q.empty()){
            string word=q.front().first;
            int step =q.front().second;
            q.pop();
            
            if(word==target)
            return  step;
            
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    
                    
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                    
                }
                word[i]=original;  //WE will recover the original word to make change and again check it 
            }
        }
        return 0;
    }
};
