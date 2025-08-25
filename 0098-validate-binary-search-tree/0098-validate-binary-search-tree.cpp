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
    bool checkValidBST(TreeNode* root, long long int minVal, long long int maxVal){
        if(!root) return true;
        return checkValidBST(root->left, minVal, root->val) and checkValidBST(root->right, root->val, maxVal) and (minVal < root->val and root->val < maxVal);
        
    }
public:
    bool isValidBST(TreeNode* root) {
        return checkValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};