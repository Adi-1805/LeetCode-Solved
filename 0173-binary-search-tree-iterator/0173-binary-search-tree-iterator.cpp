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
class BSTIterator {
        stack<TreeNode*> st;
        void pushAllLeft(TreeNode* root){
            if(!root) return ;
            TreeNode* temp = root;
            while(temp){
                st.push(temp);
                temp = temp->left;
            } 
        }

public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode* root = st.top();
        st.pop();
        pushAllLeft(root->right);
        return root->val;
    }
    
    bool hasNext() {
        return (!st.empty());
    }


};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */