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
    void reverseLL(ListNode* &head, ListNode *curNode, ListNode *prevNode){
        if(curNode -> next == NULL){
            curNode -> next = prevNode;
            head = curNode; 
            return;
        }
        
        ListNode *nextNode = curNode -> next;
        reverseLL(head, nextNode, curNode);
        curNode -> next = prevNode;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *curNode = head, *prevNode = NULL;
        reverseLL(head, curNode, prevNode);
        return head;
    }
};