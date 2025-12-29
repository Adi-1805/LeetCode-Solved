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
    void generate_parent_map(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mp){
        queue<TreeNode*> q; q.push(root);
        mp[root] = NULL;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* curr = q.front(); q.pop();
                if(curr->left){
                    q.push(curr->left); mp[curr->left] = curr;
                }
                if(curr->right){
                    q.push(curr->right); mp[curr->right] = curr;
                }
            }
        }
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> mp;
        generate_parent_map(root, mp);
        queue<TreeNode*> q; q.push(root);
        int level = 0, sum = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* curr = q.front(); q.pop();
                if(level >= 2){
                    if(mp[mp[curr]]->val % 2 == 0) sum += curr->val;
                }
                if(curr->left) q.push(curr->left); 
                if(curr->right) q.push(curr->right);
            }
            level++;
        }
        return sum;
    }
};