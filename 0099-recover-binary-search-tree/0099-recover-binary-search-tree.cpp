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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;
    void inorder(TreeNode* root){
        if(!root) return ;
        inorder(root->left);

        if(prev != NULL and prev->val > root->val){
            if(first == NULL){    
                first = prev;
            }
            second = root;
        }
        prev = root;

        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = second = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first and second) swap(first->val, second->val);
    }
};