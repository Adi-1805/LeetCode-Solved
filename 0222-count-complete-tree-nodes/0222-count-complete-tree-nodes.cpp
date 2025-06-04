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
#define ull unsigned long long
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int nodeCnt = 0;
        if(!root) return 0;
        queue<TreeNode*> q; q.push(root); // Stores node and its index
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto curr = q.front();
                q.pop(); nodeCnt++;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return nodeCnt;    
    }
};