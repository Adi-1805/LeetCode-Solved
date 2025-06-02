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
    bool check(TreeNode* p, TreeNode* q){
        if(p == NULL or q == NULL) return (p == q);
        bool lc = check(p->left, q->left);
        bool rc = check(p->right, q->right);
        return (p->val == q->val and lc and rc);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p,q);
    }
};