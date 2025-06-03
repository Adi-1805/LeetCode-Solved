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
    vector<int> ans;
    // REVERSE PREORDER: Root -> Right -> Left
    void reverse_preorder(TreeNode* root, int level){
        if(root == NULL) return;
        if(level == ans.size()) ans.push_back(root->val); // for each level there will be one value added to ans, hence this will ensure that for each level the first node traversed is pushed in ans
        reverse_preorder(root->right, level+1);
        reverse_preorder(root->left, level+1); 
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        reverse_preorder(root, 0);
        return ans;
    }
};