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
    void DFS(TreeNode* root, long int number, long long int& sum){
        if(!root){
            return;
        }
        if(!root->left and !root->right){
            number = (number*10) + root->val;
            sum += number;
        }
        
        DFS(root->left, 1LL*number*10 + root->val, sum); 
        DFS(root->right, 1LL*number*10 + root->val, sum);
    }

public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        long int number = 0;
        long long int sum  = 0;
        DFS(root, number, sum);
        return sum;
    }
};