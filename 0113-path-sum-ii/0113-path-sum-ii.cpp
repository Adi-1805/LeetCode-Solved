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
    void DFStoGetAllPathsWithTargetSum(TreeNode* root, int target, int currentSum, vector<int>& path, vector<vector<int>>& allPaths){
        if(!root) return ;
        if(!root->left and !root->right){
            if(currentSum + root->val == target){
                path.push_back(root->val);
                allPaths.push_back(path);
                path.pop_back();
            }
            return ;
        }

        path.push_back(root->val);
        DFStoGetAllPathsWithTargetSum(root->left, target, currentSum + root->val, path, allPaths);

        DFStoGetAllPathsWithTargetSum(root->right, target, currentSum + root->val, path, allPaths);
        path.pop_back();

    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> allPaths;
        DFStoGetAllPathsWithTargetSum(root, targetSum, 0, path, allPaths);
        return allPaths;
    }
};