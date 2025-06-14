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
    TreeNode* solve(TreeNode* root){
        if(!root->left) return root;
        return solve(root->left);
    }
    TreeNode* helper(TreeNode* root){
        if(!root) return nullptr;
        if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }
        TreeNode* leftSub = root->left;
        TreeNode* rightSubKaLeftestNode = solve(root->right);
        rightSubKaLeftestNode -> left = leftSub;
        return root->right;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val == key) return helper(root);
        TreeNode* temp = root;
        while(temp){
            if(temp->val < key){
                if(temp->right and temp->right->val == key){
                    temp -> right = helper(temp->right);
                    break;
                }
                temp = temp -> right;
            }
            else{
                if(temp->left and temp->left->val == key){
                    temp -> left = helper(temp->left);
                    break;
                }
                temp = temp -> left;
            }
        }
        return root;
    }
};