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
    TreeNode* joinerFunction(TreeNode* root){
        if(root->left == NULL){
            return root -> right;
        }
        else if(root->right == NULL){
            return root -> left;
        }

        TreeNode* rightmostChildOfLeftSubtree = NULL;
        TreeNode* temp = root->left;
        while(temp){
            rightmostChildOfLeftSubtree = temp;
            temp = temp -> right;
        }

        rightmostChildOfLeftSubtree->right = root -> right;
        return root -> left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root -> val == key){
            return joinerFunction(root);
        }

        TreeNode* temp = root;
        while(temp){
            if(temp->val > key){
                if(temp->left and temp->left->val == key){
                    temp -> left = joinerFunction(temp->left);
                    break;
                }
                else{
                    temp = temp -> left;
                }
            }
            else{
                if(temp->right and temp->right->val == key){
                    temp -> right = joinerFunction(temp->right);
                    break;
                }
                else{
                    temp = temp -> right;
                }
            }
        }

        return root;
    }
};