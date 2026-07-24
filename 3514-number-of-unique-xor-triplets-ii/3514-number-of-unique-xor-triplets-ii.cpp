class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st;
        for(int x: nums){
            for(int y: nums){
                st.insert(x^y);
            } 
        }
        unordered_set<int> ans;
        for(int x: nums){
            for(int val: st){
                ans.insert(x^val);
            }
        }
        return ans.size();
    }
};