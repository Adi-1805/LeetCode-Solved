class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        if(n == 1) return 0;

        int score = 0; string s1, s2; int a, b;
        if(x > y){
            s1 = "ab"; s2 = "ba"; a = x; b = y;
        }else{
            s1 = "ba"; s2 = "ab"; a = y; b = x;
        }
        
        int i = 0;
        while(i+1 < s.size()){
            if(s.substr(i, 2) == s1){
                s.erase(i,2); score += a; i = max(0, i-1);
            }
            else i++;
        }
        i = 0;
        while(i+1 < s.size()){
            if(s.substr(i, 2) == s2){
                s.erase(i,2); score += b; i = max(0, i-1);
            }
            else i++;
        }
        return score;
    }
};