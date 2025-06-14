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
    TreeNode* lca = NULL;
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || root == NULL){
            return root;
        }

        TreeNode* left = NULL; TreeNode* right = NULL;
        if(root->left) left = LCA(root->left, p, q);
        if(root->right) right = LCA(root->right, p , q);
        
        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, p, q);
    }
};