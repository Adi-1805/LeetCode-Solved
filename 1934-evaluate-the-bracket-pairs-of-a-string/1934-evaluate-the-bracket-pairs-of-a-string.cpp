class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int size = s.size();
        unordered_map<string, string> mp;
        for(auto pair: knowledge){
            mp[pair[0]] = pair[1];
        }

        string ans = "";
        int index = 0;
        
        while(index < size){
            char current = s[index];
            if(current == '('){
                string replaced = "";
                while(s[++index] != ')'){ 
                    replaced += s[index];
                }
                if(mp.find(replaced) != mp.end()) ans += mp[replaced];
                else ans += '?';
            }
            else{
                ans += current;
            }
            index++;
        }
        return ans;
    }
};