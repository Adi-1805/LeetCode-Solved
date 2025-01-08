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
    // ***********WE WILL DO A ROOT->RIGHT->LEFT traversal**********
    void traversal(TreeNode* root, int lvl, vector<int>& res){
        if(root == NULL) return ;
        if(res.size() == lvl) res.push_back(root->val);
        traversal(root->right, lvl+1, res);
        traversal(root->left, lvl+1, res);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        traversal(root, 0, result);
        return result;
    }
};