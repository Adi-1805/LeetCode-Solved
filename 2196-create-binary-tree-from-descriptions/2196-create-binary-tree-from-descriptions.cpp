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
    TreeNode* buildTree(unordered_map<int, vector<pair<int, bool>>> &pc, int rootVal){
        TreeNode *root = new TreeNode(rootVal);
        if(pc.find(rootVal) != pc.end()){
            for(auto &pair: pc[rootVal]){
                int cVal = pair.first, isL = pair.second;
                if(isL) root->left = buildTree(pc, cVal);
                else root->right = buildTree(pc, cVal);
            }
        }
        return root;
    }
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, vector<pair<int, bool>>> p_to_c;
        unordered_set<int> all, children;
        for(auto &v: descriptions){
            int p = v[0], c = v[1]; bool isL = v[2];
            all.insert(p); all.insert(c);
            children.insert(c);
            p_to_c[p].push_back({c, isL});
        }

        int rootVal = 0;
        for(int val: all){
            if(children.find(val) == children.end()){ rootVal = val; break; }
        }

        return buildTree(p_to_c, rootVal);
    }
};