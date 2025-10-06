class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // BOYER-MOORE VOTING ALGORITHM
        int n = nums.size();

        // Step 1: Find the candidate answer
        int possibleAnswer1 = 0, possibleAnswer2 = 0;
        int count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++){
            if(count1 == 0 and nums[i] != possibleAnswer2){
                possibleAnswer1 = nums[i]; count1 = 1;
            }
            else if(count2 == 0 and nums[i] != possibleAnswer1){
                possibleAnswer2 = nums[i]; count2 = 1;
            }

            else if(nums[i] == possibleAnswer1) count1++;
            else if(nums[i] == possibleAnswer2) count2++;
                
            else{
                count1--; count2--;
            }

        }

        // Step 2: Check if the candidate is truly majority element
        count1 = 0; count2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == possibleAnswer1) count1++;   
            else if(nums[i] == possibleAnswer2) count2++;   
        }

        vector<int> result;
        if(count1 > (n/3)) result.push_back(possibleAnswer1);
        if(count2 > (n/3)) result.push_back(possibleAnswer2);
        
        return result;
    }
};