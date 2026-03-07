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
    ListNode* recur(ListNode* head, int val){
        if(head == NULL) return NULL;
        head -> next = removeElements(head -> next, val);
        return (head -> val == val) ? head -> next : head;
    }
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy_head = new ListNode(0); 
        dummy_head -> next = head;
        return recur(dummy_head -> next, val);
    }
};