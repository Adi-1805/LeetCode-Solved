class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int val: nums){
            if(st.count(val)) return true;
            st.insert(val);
        }
        return false;
    }
};