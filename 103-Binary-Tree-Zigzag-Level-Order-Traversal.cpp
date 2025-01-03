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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};

        vector<vector<int>> levels;
        deque<TreeNode*> q; q.push_front(root);

        int lvl =1;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++){
                if(lvl&1){
                    TreeNode* curNode = q.front();
                    q.pop_front();
                    if(curNode->left != NULL) q.push_back(curNode->left);
                    if(curNode->right != NULL) q.push_back(curNode->right);
                    level.push_back(curNode->val); 
                }
                else{
                    TreeNode* curNode = q.back();
                    q.pop_back();
                    if(curNode->right != NULL) q.push_front(curNode->right);
                    if(curNode->left != NULL) q.push_front(curNode->left);
                    level.push_back(curNode->val); 
                }
            }
            levels.push_back(level); lvl++;
        }
        return levels;
    }
};