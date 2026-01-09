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
    int getDepth(TreeNode* root){
        if(!root) return 0;
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, int max_depth, int cur_depth){
        if(!root) return nullptr;
        if(cur_depth == max_depth) return root;
        TreeNode* left = lowestCommonAncestor(root->left, max_depth, cur_depth+1);
        TreeNode* right = lowestCommonAncestor(root->right, max_depth, cur_depth+1);
        if(left && right) return root;
        return left ? left : right;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int max_depth = getDepth(root);
        int cur_depth = 1; // root at level 1
        return lowestCommonAncestor(root, max_depth, cur_depth);
    }
};