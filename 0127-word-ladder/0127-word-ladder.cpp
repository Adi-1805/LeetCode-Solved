class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*
         Okay so here you have to return the number of words in the sequence of transformation rather than length of the transformation sequence. Hence if the beginWord is in the list, it will be counted, else not. I will take care of it in the start itself as follows:
        */

        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end()); 
        q.push({beginWord, 1});
        st.erase(beginWord);

        if(st.find(endWord) == st.end()) return 0;

        int answer = 0;
        while(!q.empty()){
            auto [s, len]= q.front();
            q.pop();
            for(int i = 0; i < s.size(); i++){
                char orig = s[i]; // to trace back
                for(char ch = 'a'; ch <= 'z'; ch++){
                    s[i] = ch;
                    if( st.find(s) != st.end() ){
                        q.push({s, len+1});
                        st.erase(s);
                    }
                }
                s[i] = orig;
            }
            if(s == endWord) return len;

        }
        return 0;
    }
};