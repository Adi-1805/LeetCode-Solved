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
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q; q.push(root);
        int required_level = 0, current_level = 1; long long max_level_sum = LLONG_MIN;
        while(!q.empty()){
            int n = q.size();
            long long  level_sum = 0;
            while(n--){
                TreeNode* cur = q.front(); q.pop();
                level_sum += cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right); 
            }
            if(level_sum > max_level_sum){
                max_level_sum = level_sum;
                required_level = current_level;
            }
            current_level++;
        }
        return required_level;
    }
};