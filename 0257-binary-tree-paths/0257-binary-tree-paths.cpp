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
    vector<vector<int>> ans;
    vector<int> temp;
    void getPath(TreeNode* root){
        if(!root) return;
        temp.push_back(root->val);
        if(!root->left and !root->right){
            ans.push_back(temp);
        }
        getPath(root->left);
        getPath(root->right);
        temp.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        getPath(root);
        vector<string> arr;
        for(auto vec: ans){
            string s = "";
            for(int val: vec){
                s += to_string(val);
                s += "->";
            }
            s.pop_back(); 
            s.pop_back(); 
            arr.push_back(s);
        }
        return arr;
    }
};