/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parent_child;
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q; q.push(root);

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node->left){
                parent_child[node->left] = node; q.push(node->left);
            }
            if(node->right){
                parent_child[node->right] = node; q.push(node->right);
            }
        }

        q.push(target); visited[target] = 1; 
        int cur_dist = 0;
        while(!q.empty()){
            int n = q.size(); cur_dist++;
            if(cur_dist > k) break;

            for(int i = 0; i < n; i++){
                auto node = q.front(); q.pop(); 
                
                if(node->left and !visited[node->left]){
                    q.push(node->left); visited[node->left] = 1;
                }
                if(node->right and !visited[node->right]){
                    q.push(node->right); visited[node->right] = 1;
                }
                if( parent_child[node] and !visited[parent_child[node]]){
                    q.push(parent_child[node]); visited[parent_child[node]] = 1;
                }
            }
        }
        vector<int> result;
        while(!q.empty()){
            auto node = q.front(); q.pop();
            result.push_back(node->val);
        }
        return result;
    }
};