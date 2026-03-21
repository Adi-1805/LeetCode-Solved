class Solution {
    bool isPldrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]) return 0;
        }
        return 1;
    }
    void recur(int ind, string s, vector<vector<string>> &result, vector<string> &parts){
        if(ind == s.size()){
            result.push_back(parts); return;
        }
        
        for(int i = ind; i < s.size(); i++){
            if(isPldrome(s, ind, i)){
                parts.push_back(s.substr(ind, i-ind+1));
                recur(i+1, s, result, parts);
                parts.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> parts;
        recur(0, s, result, parts);
        return result;
    }
};