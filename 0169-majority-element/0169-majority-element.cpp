class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // BOYER-MOORE VOTING ALGORITHM
        int n = nums.size();

        // Step 1: Find the candidate answer
        int possibleAnswer = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(count == 0){
                possibleAnswer = nums[i]; count = 1;
            }else{
                if(nums[i] == possibleAnswer) count++;
                else count--;
            }
        }

        // Step 2: Check if the candidate is truly majority element
        count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == possibleAnswer) count++;   
        }

        if(count > floor(n/2)) return possibleAnswer;

        return -1;
    }
};