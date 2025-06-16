class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse;

    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = reverse ? node->right : node->left;
        }
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();
        if (!reverse) {
            pushAll(node->right);
        } else {
            pushAll(node->left);
        }
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIterator leftIt(root, false);  // Forward iterator
        BSTIterator rightIt(root, true);  // Reverse iterator

        int left = leftIt.next();
        int right = rightIt.next();

        while (left < right) {
            int sum = left + right;
            if (sum == k) {
                return true;
            } else if (sum < k) {
                left = leftIt.next();
            } else {
                right = rightIt.next();
            }
        }
        return false;
    }
};