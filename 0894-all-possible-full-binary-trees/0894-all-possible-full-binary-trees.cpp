/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<int, vector<TreeNode*>> dp; 
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> result;
        if((n&1) == 0) return {}; // for even values of n -> no tree possible
        if(n == 1){
            TreeNode* root = new TreeNode(0); return {root};
        }
        if(dp.find(n) != dp.end()) return dp[n];

        for(int i = 1; i < n-1; i+=2){
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n-i-1);
            dp[i] = left, dp[n-i-1] = right;

            for(auto L: left){
                for(auto R: right){
                    TreeNode* root = new TreeNode(0);
                    root->left = L;
                    root-> right = R;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};