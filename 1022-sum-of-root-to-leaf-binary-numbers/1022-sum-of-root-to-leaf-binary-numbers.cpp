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
    void DFS(TreeNode* root, string binary_int, long long int& sum){
        if(!root){
            return;
        }
        if(!root->left and !root->right){
            char cur_bit = '0' + (root->val);
            bitset<32> bt(binary_int + cur_bit);
            cout << bt.to_ullong() << endl;
            sum += bt.to_ullong();
        }

        char cur_bit = '0' + (root->val);
        DFS(root->left, binary_int + cur_bit, sum); 
        DFS(root->right, binary_int + cur_bit, sum);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        long long int sum  = 0;
        DFS(root, "", sum);
        return sum;
    }
};