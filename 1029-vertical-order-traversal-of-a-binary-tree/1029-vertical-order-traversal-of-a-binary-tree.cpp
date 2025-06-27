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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp; // col then row then multiset containing node values
        queue< pair<pair<int, int>, TreeNode*> > q;
        q.push({{0, 0}, root});

        while(!q.empty()){
            auto row = q.front().first.first;
            auto col = q.front().first.second;
            auto node = q.front().second;
            q.pop();
            mp[col][row].insert(node->val);
            if(node->left) q.push({{row+1, col-1}, node->left});
            if(node->right) q.push({{row+1, col+1}, node->right});
        }

        vector<vector<int>> ans;
        for(auto& [col, rowMap]: mp){ 
            vector<int> vlevel;
            for(auto& [row, mlt]: rowMap){
                for(int val: mlt){
                    vlevel.push_back(val);
                }
            }
            ans.push_back(vlevel);

        }
        return ans;
        
    }
};