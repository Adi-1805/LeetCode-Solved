class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if( nums.size() == 0 ) return 0;

        set<int> s(nums.begin(), nums.end());
        int maxlen = 0, curlen = 0;
        for(auto it: s){
            if( s.find(it-1 ) == s.end()){
                int curNo = it; 
                curlen = 1;
                
                while( s.find(curNo+1) != s.end()){
                    curlen++;
                    curNo++;
                }
            }
            maxlen = max(maxlen, curlen);
        }
        return maxlen;
    }
};