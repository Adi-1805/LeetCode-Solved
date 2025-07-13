//Recursion 2nd way 
class Solution {
public:
    int recur(int index, int sum, int n, int target, vector<int>& nums){
        if(index == n){
            if(sum == target) return 1;
            else return 0;
        }
        int take = recur(index+1, sum+nums[index], n, target, nums);
        int not_take = recur(index+1, sum, n, target, nums);

        return take+not_take;
    } 
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }

        if((target+sum)%2 != 0) return 0;
        int a = (target+sum)/2;

        return recur(0, 0, n, a, nums);
    }
};