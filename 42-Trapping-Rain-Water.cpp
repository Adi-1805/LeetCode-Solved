class Solution {
public:
    vector<int> prefixMax(vector<int>& arr){
        int n = arr.size();
        vector<int> result(n,0);
        result[0] = arr[0];
        for(int i = 1; i < arr.size(); i++){
            result[i] = max(result[i-1], arr[i]);
        }
        return result;
    }
    vector<int> suffixMax(vector<int>& arr){
        int n = arr.size();
        vector<int> result(n,0);
        result[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--){
            result[i] = max(result[i+1], arr[i]);
        }
        return result;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax = prefixMax(height);
        vector<int> rightMax = suffixMax(height);
        int totalArea = 0;
        for(int i = 0; i < n; i++){
            if(height[i] < leftMax[i] and height[i] < rightMax[i]){
                totalArea += min(leftMax[i], rightMax[i]) - height[i];
            }
        }
        return totalArea;
    }
};