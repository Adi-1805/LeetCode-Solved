/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* firstNodeInTheRange(TreeNode* root, int minVal, int maxVal) {
        if(!root) return root;
        if(root->val < minVal and root->val < maxVal){
            return firstNodeInTheRange(root->right, minVal, maxVal);
        }
        if(root->val > minVal and root->val > maxVal){
            return firstNodeInTheRange(root->left, minVal, maxVal);
        }
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return firstNodeInTheRange(root, p->val, q->val);
    }
};