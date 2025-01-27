class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int result = 0;
        for(char ch: s){
            if(ch == '('){
                st.push(ch);
            }
            else if(ch == ')'){
                if(st.size() > result) result = st.size();
                st.pop();
            }
        }
        return result;
    }
};