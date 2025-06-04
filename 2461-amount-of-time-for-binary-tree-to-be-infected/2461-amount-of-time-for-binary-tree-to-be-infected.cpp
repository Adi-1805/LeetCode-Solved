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
    void findTarget(TreeNode* root, int target, TreeNode*& temp){
        if(root == NULL) return ;
        if(root->val == target){
            temp = root; return;
        }
        findTarget(root->left, target, temp);
        findTarget(root->right, target, temp);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        // Mark parent children nodes
        unordered_map<TreeNode*, TreeNode*> parent_child;
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            if(curr->left){
                parent_child[curr->left] = curr; q.push(curr->left);
            }
            if(curr->right){
                parent_child[curr->right] = curr; q.push(curr->right);
            }
        }
        // Find start node address
        TreeNode* startNode = NULL; findTarget(root, start, startNode);

        // Start traversing in all direction from the startNode
        int cur_dist = 0;
        unordered_map<TreeNode*, int> vis; 
        q.push(startNode); vis[startNode] = 1;
        while(!q.empty()){
            int n = q.size(); cur_dist++;
            while(n--){
                auto curr = q.front();
                q.pop();
                if(curr->left and !vis[curr->left]){
                    vis[curr->left] = 1; q.push(curr->left);
                }
                if(curr->right and !vis[curr->right]){
                    vis[curr->right] = 1; q.push(curr->right);
                }
                if(parent_child.find(curr) != parent_child.end() and !vis[parent_child[curr]]){
                    vis[parent_child[curr]] = 1; q.push(parent_child[curr]);
                }
            }
        }
        return --cur_dist;
    }
};