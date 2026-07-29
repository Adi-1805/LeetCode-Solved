class Solution {
public:
    string smallestSubsequence(string s) {
        bitset<27> seen; string st;
        int freq[27] = {0}; for(auto& c : s) freq[c & 31]++;

        for(auto& c : s){
            int x = c & 31;
            freq[x]--;
            if(seen.test(x)) continue;
            while(st.length() && st.back() > c && freq[st.back() & 31]){
                seen.reset(st.back() & 31);
                st.pop_back();
            }
            st.push_back(c);
            seen.set(x);
        }
        return st;
    }
};