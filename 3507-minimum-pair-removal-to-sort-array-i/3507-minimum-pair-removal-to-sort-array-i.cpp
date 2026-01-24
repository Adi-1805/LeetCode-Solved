class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
       int n = nums.size(), ops = 0;
        bool increasing = 0;
       while(!increasing){
            if(is_sorted(nums.begin(), nums.end())){
                increasing = 1;
            }else{
                int minsum = INT_MAX, ind = -1;
                for(int i = 1; i < nums.size(); i++){
                    int sum = nums[i-1] + nums[i];
                    if(sum < minsum){
                        minsum = sum;
                        ind = i;
                    }
                }
                ops++;
                nums[ind -1] = minsum;
                nums.erase(nums.begin()+ind);
            }
       }
       return ops;
    }
};