class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        string curr = "";
        for(int i = 0; i < num.size()-2; i++)
        {
            if(num[i] == num[i+1] && num[i] == num[i+2])
            {
                curr = num.substr(i,3);
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};