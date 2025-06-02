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
    int pathSum(TreeNode* root, int& maxSum){
        if (root == NULL) return 0;
        int curr = root -> val;
        int ls = max(0, pathSum(root->left, maxSum));
        int rs = max(0, pathSum(root->right, maxSum));
        maxSum = max(maxSum, curr + ls + rs);
        return max(ls,rs) + curr;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = root->val;
        int sum = pathSum(root, maxSum); // sum returns sum of all nodes
        // cout << sum << endl; 
        return max(maxSum, root->val); // in case there is only on node or the path has less sum than node value e.g.,[2,-1]
    }
};