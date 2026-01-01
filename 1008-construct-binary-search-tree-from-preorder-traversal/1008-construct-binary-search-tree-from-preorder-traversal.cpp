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
    TreeNode* makeTree(vector<int> &pre, vector<int> &in, int &preInd, int inS, int inE){
        if(preInd == pre.size() || (inS > inE)) return NULL;
        
        int rootVal = pre[preInd++];
        int pivot = find(in.begin()+inS, in.begin()+inE+1, rootVal) - in.begin();
        TreeNode* root = new TreeNode(in[pivot]);
        root -> left = makeTree(pre, in, preInd, inS, pivot-1);
        root -> right = makeTree(pre, in, preInd, pivot+1, inE);

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        int n = preorder.size();
        int preInd = 0;
        return makeTree(preorder, inorder, preInd, 0, n-1);
    }
};