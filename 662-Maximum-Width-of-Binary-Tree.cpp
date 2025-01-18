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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        
        deque < pair<TreeNode*,unsigned long long int> > q;
        q.push_front({root, 1});
        unsigned long long int maxWidth = 0;
        
        while(!q.empty()){
            int n = q.size();
            // calculating the maxWidth at the start of the while loop because if at the end of the loop, we might get an error because q could be empty so either put it at the start or put it in the end with a condition
            maxWidth = max(maxWidth, q.back().second - q.front().second +1);

            for(int i = 0; i < n; i++){
                auto[curNode, ind] = q.front();    
                q.pop_front();

                TreeNode* left = curNode-> left;
                TreeNode* right = curNode-> right;

                if(left != NULL) q.push_back({left, 1ULL*ind*2+1}); 
                if(right != NULL) q.push_back({right, 1ULL*ind*2+2}); 

            }
        }
        return maxWidth;
    }
};