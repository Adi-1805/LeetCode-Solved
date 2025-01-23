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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) return new TreeNode(val);
        TreeNode* curNode = root;
        while(true){
            if(curNode->val <= val){
                if(curNode->right) curNode = curNode->right;
                else{ curNode->right = new TreeNode(val); break; }
            }
            else{
                if(curNode->left) curNode = curNode->left;
                else{ curNode->left = new TreeNode(val); break; }
            }
        }
        return root;
    }
};