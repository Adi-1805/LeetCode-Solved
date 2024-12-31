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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int leftSubTree = maxDepth(root -> left);
        int rightSubTree = maxDepth(root -> right);
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;


        if(abs(leftSubTree - rightSubTree) > 1) return false;

        bool left = isBalanced(root -> left);
        bool right = isBalanced(root -> right);

        return left && right;
    }
};