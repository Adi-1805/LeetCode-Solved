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
 #define ull unsigned long long int
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        ull maxLen = 0;
        queue<pair<TreeNode*, ull>> q; q.push({root, 0}); // Stores node and its index
        while(!q.empty()){
            vector<ull> nodeIndexOfEachLevel;
            int n = q.size();
            while(n--){
                auto curr = q.front().first;
                ull ind = q.front().second;
                q.pop();
                nodeIndexOfEachLevel.push_back(ind);
                if(curr->left) q.push({curr->left, 1LL*2*ind});
                if(curr->right) q.push({curr->right, 1LL*2*ind+1});
            }
            ull curLen = 1LL*(nodeIndexOfEachLevel.back() - nodeIndexOfEachLevel[0] + 1);
            maxLen = max(curLen, maxLen);
        }
        return maxLen;
    }
};