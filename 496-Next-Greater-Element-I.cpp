class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        st.push(INT_MAX);
        unordered_map<int,int> mp;
        for(int i = nums2.size()-1; i >= 0; i--){
            int curNum = nums2[i];
            while(st.top() <= curNum and !st.empty()){
                st.pop();
            }
            mp[curNum] = st.top() == INT_MAX ? -1 : st.top();
            st.push(curNum);
        }
        vector<int> ans;
        for(int val: nums1){
            ans.push_back(mp[val]);
        }
        return ans;
    }
};