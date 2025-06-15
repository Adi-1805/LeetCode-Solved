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
    TreeNode* makeBST(vector<int>&arr, int& ind, long maxVal){
        if(ind == arr.size() or arr[ind] > maxVal) return NULL;
        TreeNode* root = new TreeNode(arr[ind++]);
        root -> left = makeBST(arr, ind, root->val);
        root -> right = makeBST(arr, ind, maxVal); 
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return makeBST(preorder, index, LONG_MAX); 
    }
};