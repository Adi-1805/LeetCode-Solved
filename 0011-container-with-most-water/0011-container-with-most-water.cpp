#define ll long long
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        ll left = 0, right = n-1;
        ll maxArea = LLONG_MIN, area = 0;
        while(left < right){
            area = (right - left)*( min(height[left], height[right]) );
            if(height[left] > height[right]){
                right--;
            }
            else left++;
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};