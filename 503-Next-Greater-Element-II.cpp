class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st; st.push(INT_MAX);
        vector<int> result;
        for(int i = 2*n-1; i >= 0; i--){
            int curNum = nums[i%n];
            while(st.top() <= curNum and !st.empty()){
                st.pop();
            }
            if(i < n) st.top() == INT_MAX ? result.push_back(-1) : result.push_back(st.top());
            st.push(curNum);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};