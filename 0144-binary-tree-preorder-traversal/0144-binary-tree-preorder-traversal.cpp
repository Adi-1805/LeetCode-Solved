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
    vector<int> preorder;
    // vector<int> inorder;
    // vector<int> postorder;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root==NULL) return {};
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            int n = st.size();
            for(int i = 0; i < n; i++){
                auto CurNode = st.top();
                st.pop();
                preorder.push_back(CurNode->val);
                if(CurNode->right) st.push(CurNode->right);
                if(CurNode->left) st.push(CurNode->left);
            }
        }
        return preorder;
    }
};