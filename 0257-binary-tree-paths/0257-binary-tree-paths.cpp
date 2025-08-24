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
    vector<string> result;
    void DFS(TreeNode* root, string path){
        if(!root) return;
        if(!root->left and !root->right){
            path = path + to_string(root->val);
            result.push_back(path);
            path.clear();
            return;
        }

        DFS(root->left, path + to_string(root->val) + "->");
        DFS(root->right, path + to_string(root->val) + "->");
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        DFS(root, path);
        return result;
    }
};