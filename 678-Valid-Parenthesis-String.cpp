class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0;
        for(auto it: s){
            left += (it == '(') ? 1:-1;
            right += (it == ')') ? -1:1;
            if(right < 0) break;
            left = max(left,0);
        }
        return (left == 0);
    }
};