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
class FindElements {
    unordered_map<int, bool> present;
    void DFS_Preorder(TreeNode* root, int index){
        if(root == NULL) return ;
        root->val = index;
        present[root->val] = 1;
        if(root->left){
            root->left->val = index*2 + 1;
            DFS_Preorder(root->left, index*2 + 1);
        }
        if(root->right){
            root->right->val = index*2 + 2;
            DFS_Preorder(root->right, index*2 + 2);
        }
    }
public:
    FindElements(TreeNode* root) {
        DFS_Preorder(root, 0);
    }
    
    bool find(int target) {
        return (present.count(target) > 0);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */