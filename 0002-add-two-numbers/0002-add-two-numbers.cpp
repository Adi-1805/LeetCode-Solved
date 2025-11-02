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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        // dummy -> next = head;
        while(l1 and l2){
            int digit1 = l1 -> val;
            int digit2 = l2 -> val;
            int sum = (digit1 + digit2 + carry);
            carry = sum/10;
            temp -> next = new ListNode(sum % 10);
            temp = temp -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1){
            int digit1 = l1 -> val;
            int sum = (digit1 + carry);
            carry = sum/10;
            temp -> next = new ListNode(sum % 10);
            temp = temp -> next;
            l1 = l1 -> next;
        }
        while(l2){
            int digit2 = l2 -> val;
            int sum = (digit2 + carry);
            carry = sum/10;
            temp -> next = new ListNode(sum % 10);
            temp = temp -> next;
            l2 = l2 -> next;
        }
        if(carry != 0){
            temp -> next = new ListNode(carry);
        }
        return dummy -> next;
    }
};