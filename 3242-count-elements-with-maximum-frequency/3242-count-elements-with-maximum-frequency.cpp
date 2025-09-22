class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> hash(101, 0);
        int maxFreq = 0;
        int cnt = 0;
        for(int val: nums){
            ++hash[val];
            if(hash[val] == maxFreq) cnt++;
            else if(hash[val] > maxFreq){
                maxFreq = hash[val];
                cnt = 1;
            } 
        }
        return cnt*maxFreq;
    }
};