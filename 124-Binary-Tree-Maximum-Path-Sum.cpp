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
    int getSum(TreeNode* root, int& maxSum){
        if(root == NULL) return 0;

        int leftSum = getSum(root->left, maxSum);
        int rightSum = getSum(root->right, maxSum);

        if (leftSum < 0) leftSum = 0;
        if (rightSum < 0) rightSum = 0;
        // above checks so that we do not add a negative valued node to the maxSum, cuz it won't be included even if it is part of the path

        maxSum = max(maxSum, root -> val + leftSum + rightSum);

        return (root -> val) + max(leftSum, rightSum) ;
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        getSum(root, sum);
        return sum;
    }
};