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
    // maxDepth code for LeetCode 104, edited for finding Balanced BT
    int checkBBT(TreeNode* root) {
        if(root == NULL) return 0;

        int leftSubTree = checkBBT(root -> left);
        int rightSubTree = checkBBT(root -> right);
        
        if(leftSubTree == -1 || rightSubTree == -1) return -1;
        if(abs(leftSubTree - rightSubTree) > 1) return -1;

        return 1 + max(leftSubTree, rightSubTree);
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        return (checkBBT(root) != -1) ? true : false;
    }
};