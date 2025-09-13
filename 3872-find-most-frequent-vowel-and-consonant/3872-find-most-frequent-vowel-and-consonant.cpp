class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> abc(26, 0);
        int maxConsonantFreq = 0;
        int maxVowelFreq = 0;
        for(char ch: s){
            if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') {
                abc[ch - 'a']++;
                if(maxVowelFreq < abc[ch-'a']) maxVowelFreq = abc[ch-'a'];
            }
            else {
                abc[ch - 'a']++;
                if(maxConsonantFreq < abc[ch - 'a']) maxConsonantFreq = abc[ch - 'a'];
            } 
        }
        return maxConsonantFreq + maxVowelFreq;
    }
};