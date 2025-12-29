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
    void inorder(vector<TreeNode*> &in, TreeNode* root){
        if(!root) return ;
        inorder(in, root->left);
        in.push_back(root);
        inorder(in, root->right);
    }
    TreeNode* makeTree(vector<TreeNode*> in, int s, int e){
        if(s > e) return NULL;
        int mid = s+(e-s)/2;
        TreeNode* root = new TreeNode(in[mid]->val);
        root->left = makeTree(in, s, mid-1);
        root->right = makeTree(in, mid+1, e);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> in; inorder(in, root);
        return makeTree(in, 0, in.size()-1);
    }
};