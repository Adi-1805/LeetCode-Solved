/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        int ans = 0;
        ListNode *fast = head, *slow = head;
        while(fast != NULL){
            st.push(slow->val);
            slow = slow -> next; fast = fast -> next -> next;
        }  

        while(slow != NULL){
            ans = max(ans, slow->val + st.top()); st.pop();
            slow = slow-> next;
        }
        return ans;
    }
};