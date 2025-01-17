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
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size(); // everytime n will be equal to current level size

            for(int i = 0; i < n; i++){
                TreeNode* curNode = q.front();
                level.push_back(curNode->val);
                q.pop();
                if(curNode->left != NULL) q.push(curNode->left);
                if(curNode->right != NULL) q.push(curNode->right);
            }

            levels.push_back(level);
            level.clear();
        }

        return levels;
    }
};