/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* findLCA(TreeNode* root, int pVal, int qVal){
        if(!root or !root->left and !root->right) return NULL;
       
        if(root->val > pVal and root->val > qVal) return findLCA(root->left, pVal, qVal);
        else if(root->val < pVal and root->val < qVal) return findLCA(root->right, pVal, qVal);
        else return root;

        return NULL;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root, p->val, q->val);
    }
};