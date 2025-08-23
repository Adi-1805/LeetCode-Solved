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
    bool getPathWithTargetSum(TreeNode* root, int currentSum, int target){
        if(!root) return 0;
        if(!root->left and !root->right) {
            if(currentSum + root->val == target) return 1;
            return 0;
        }

        bool leftCheck = getPathWithTargetSum(root->left, currentSum + root->val, target);
        bool rightCheck = getPathWithTargetSum(root->right, currentSum + root->val, target);

        return leftCheck or rightCheck;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return getPathWithTargetSum(root, 0, targetSum);
    }
};