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
    // void traverse(TreeNode* root, vector<int>& arr){
    //     if(root == NULL) return ;
    //     traverse(root->left, arr);
    //     traverse(root->right, arr);
    //     arr.push_back(root->val);
    // }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        // use the first stack to traverse the tree in root->right->left order
        while (!st1.empty()) {
            TreeNode* curr = st1.top();
            st1.pop();
            st2.push(curr);

            if (curr->left) st1.push(curr->left);
            if (curr->right) st1.push(curr->right);
        }

        // use the second stack to reverse the order to left->right->root
        while (!st2.empty()) {
            result.push_back(st2.top()->val);
            st2.pop();
        }

        return result;
    }
};