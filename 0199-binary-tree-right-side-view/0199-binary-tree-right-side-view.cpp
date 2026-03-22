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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        
        queue <pair<TreeNode*, int>> q; q.push({root, 0});
        map<int, TreeNode*> mp;  mp[0] = root; 
       
        while(!q.empty()){
            auto [curNode, lvl] = q.front();
            q.pop();

            mp[lvl] = curNode;

            if(curNode -> left != NULL){
                q.push({curNode->left, lvl+1});
            }
            if(curNode -> right != NULL){
                q.push({curNode->right, lvl+1});
            }   
        }
        vector<int> result;
        for(auto it: mp){
            result.push_back(it.second->val);
        }
        return result;
    }
};