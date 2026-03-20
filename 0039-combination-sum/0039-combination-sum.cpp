class Solution {
    void recur(int i, vector<int> &arr, vector<vector<int>> &result, int sum, vector<int> &permut, int k){
        if(i == arr.size()){
            if(sum == k) result.push_back(permut); return;
        }
        recur(i+1, arr, result, sum, permut, k); // skip
        if(sum + arr[i] <= k) {
            permut.push_back(arr[i]);
            recur(i, arr, result, sum+arr[i], permut, k); // pick (multiple time in this case)
            permut.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> permut;
        recur(0, candidates, result, 0, permut, target);
        return result;
    }
};