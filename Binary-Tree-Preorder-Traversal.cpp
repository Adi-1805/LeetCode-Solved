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
    void traverse(TreeNode* root, vector<int>& nodes){
        if(root == NULL) return;

        nodes.push_back(root->val);
        traverse(root->left, nodes);
        traverse(root->right, nodes);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> nodes;
        stack <TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curNode = st.top();
            nodes.push_back(curNode->val);
            st.pop();
            if(curNode->right != NULL) st.push(curNode->right);
            if(curNode->left != NULL) st.push(curNode->left);
        }
        return nodes;
    }
};