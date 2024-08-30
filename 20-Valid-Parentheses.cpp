class Solution {
public:
    unordered_map<char,int> symbols = {{'(',-1},{'{',-2},{'[',-3},{')',1},{'}',2},{']',3}};
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(symbols[s[i]] < 0){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return 0;
                if( symbols[ st.top()] + symbols[s[i]] != 0 ) return 0;
                st.pop();
            }
        }
        if(st.empty()) return 1;
        return 0;
    }
};