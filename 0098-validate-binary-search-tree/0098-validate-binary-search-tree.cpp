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
    vector<int> in;
    void inorder(TreeNode* root){
        if(!root) return ;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        inorder(root);
        set<int> st(in.begin(), in.end());
        return is_sorted(in.begin(), in.end()) and (in.size() == st.size());
    }
};