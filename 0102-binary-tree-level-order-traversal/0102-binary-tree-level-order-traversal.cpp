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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> levels;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int n = q.size();
            for(int i = 0; i < n; i++){
                auto curNode = q.front();
                q.pop();
                level.push_back(curNode->val);
                if(curNode->left) q.push(curNode->left);
                if(curNode->right) q.push(curNode->right);
            }
            levels.push_back(level);
        }
        return levels;
    }
};