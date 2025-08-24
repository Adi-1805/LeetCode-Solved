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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> lvlOrderBottom;
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> lvl;
            while(n--){
                auto node = q.front();
                q.pop();
                lvl.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            lvlOrderBottom.push_back(lvl);
        }
        reverse(lvlOrderBottom.begin(), lvlOrderBottom.end());
        return lvlOrderBottom;
    }
};