/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        // detecting cycle
        bool cycle = 0; // assuming no cycle
        while(fast != NULL and fast->next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) { cycle = 1; break; }
        }
        if(!cycle) return NULL;
        // finding where cycle begins
        fast = head;
        while(slow != fast){
            fast = fast -> next;
            slow = slow -> next;
        }
        return fast;
    }
};