class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> hash(101, 0);
        int maxFreq = 0;
        for(int val: nums){
            ++hash[val];
            if(hash[val] > maxFreq) maxFreq = hash[val];
        }
        int cnt = 0;
        for(int val: hash){
            if(val == maxFreq) cnt++;
        }
        return cnt*maxFreq;
    }
};