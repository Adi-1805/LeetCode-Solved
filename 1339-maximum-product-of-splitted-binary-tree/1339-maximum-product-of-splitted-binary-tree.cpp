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
    const int M = 1e9+7;
    void getSum(TreeNode* root, long long &sum){
        if(!root) return;
        sum = (sum + root->val)%M;
        getSum(root->left, sum);
        getSum(root->right, sum);
    }
    long long getMaxProd(TreeNode* root, long long total_sum, long long &max_prod){
        if(!root) return 0;
        long left_sum = getMaxProd(root->left, total_sum, max_prod);
        long right_sum = getMaxProd(root->right, total_sum, max_prod);
        long subtree_sum = root->val + left_sum + right_sum;
        max_prod = max(max_prod, subtree_sum*(total_sum-subtree_sum));
        return root->val + left_sum + right_sum;
    }
public:
    int maxProduct(TreeNode* root) {
        long long total_sum = 0;
        getSum(root, total_sum);
        long long max_prod = 1;
        getMaxProd(root, total_sum, max_prod);
        return max_prod%M;
    }
};