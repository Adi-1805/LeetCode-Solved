class Solution {
    bool solve(vector<double>& nums){
        int n=nums.size();
        if(n==1) return abs(nums[0]-24.0)<0.000001; 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double a=nums[i],b=nums[j]; 
                vector<double> op=calculate(a,b); 
                vector<double> next;
                for(int k=0;k<n;k++){
                    if(k!=i && k!=j) next.push_back(nums[k]); 
                }
                for(auto o:op){
                    next.push_back(o);
                    if(solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
    vector<double> calculate(double a,double b){ 
        vector<double> ans;
        ans.push_back(a+b);
        ans.push_back(a-b);
        ans.push_back(b-a);
        ans.push_back(a*b);
        ans.push_back(a/b);
        ans.push_back(b/a);
        return ans;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for(int i:cards) nums.push_back((double)i);
        return solve(nums);
    }
};