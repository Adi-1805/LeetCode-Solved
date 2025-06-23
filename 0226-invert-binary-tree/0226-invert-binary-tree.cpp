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
    void Swap(TreeNode* root){
        if(!root) return ;
        swap(root->left, root->right);
        Swap(root->left);
        Swap(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        Swap(root);
        return root;
    }
};