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
        int cur_dist = 0;
        cout << q.size() << endl;
        unordered_map<TreeNode*, int> vis; 
        q.push(target); vis[target] = 1;
        while(!q.empty()){
            if(cur_dist == k) break;
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
        vector<int> ans;
        while(!q.empty()){
            auto node = q.front(); q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};