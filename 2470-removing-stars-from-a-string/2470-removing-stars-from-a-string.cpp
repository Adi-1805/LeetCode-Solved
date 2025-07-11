class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch >= 'a' and ch <= 'z'){
                st.push(ch);
            }
            else if(ch == '*' and !st.empty()){
                st.pop();
            }
        }
        string ans = "";
        while(!st.empty()){
            char ch = st.top();
            ans += ch;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};