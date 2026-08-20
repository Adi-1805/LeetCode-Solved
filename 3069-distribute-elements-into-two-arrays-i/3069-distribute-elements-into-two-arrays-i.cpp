class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> A, B;
        A.push_back(nums[0]); B.push_back(nums[1]);
        for(int i = 2; i < n; i++){ 
            if(A.back() > B.back()) A.push_back(nums[i]);
            else B.push_back(nums[i]);
        }        
        A.insert(A.end(), B.begin(), B.end());
        return A;
    }
};