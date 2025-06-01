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
    // edited the maxDepth function from Leetcode 104 so that we can calculate the max diameter through the recursion
    int Height(TreeNode* root, int& MaxD){
        if(root == NULL) return 0;

        int leftHeight = Height(root->left, MaxD);
        int rightHeight = Height(root->right, MaxD);

        MaxD = max(MaxD, leftHeight + rightHeight);

        return 1+ max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        Height(root, diameter);
        return diameter;
    }
};