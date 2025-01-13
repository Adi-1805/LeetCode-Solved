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
public:
    TreeNode* findCommon(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL or root == p or root == q) return root;
        TreeNode* left = findCommon(root->left, p, q);
        TreeNode* right = findCommon(root->right, p, q);

        if(left == NULL) return right;
        else if(right == NULL) return left;
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findCommon(root, p, q);
    }
};