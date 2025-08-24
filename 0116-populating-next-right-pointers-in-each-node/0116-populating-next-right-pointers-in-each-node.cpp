/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    void makeLeftConnection(Node* root, Node* parent){
        root -> next = parent -> right;
    }
    void makeRightConnection(Node* root, Node* parent){
        if(parent->next == NULL){
            root->next = NULL;
            return ;
        }
        root -> next = parent -> next -> left;
    }
    void helper(Node* root){
        if(!root) return;
        
        if(root->left){
            makeLeftConnection(root->left, root);
        }
        if(root->right){
            makeRightConnection(root->right, root);
        }

        helper(root->left);
        helper(root->right);
    }
public:
    Node* connect(Node* root) {
        helper(root);
        return root;
    }
};