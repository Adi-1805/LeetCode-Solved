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
        ListNode* tortoise = head;
        ListNode* hare = head;
        while(hare != NULL and hare->next != NULL){
            hare = (hare -> next) -> next;
            tortoise = tortoise -> next;
            if(hare == tortoise){
                hare = head;
                while(hare != tortoise){
                    hare =  hare -> next;
                    tortoise = tortoise -> next;
                }
                return hare;   
            }
        }
        return NULL;
    }
};