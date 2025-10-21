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
    ListNode* reverseLL(ListNode* head){
        ListNode *prevNode = NULL, *curNode = head, *nextNode = head;
        while(curNode != NULL){
            nextNode = curNode -> next;
            curNode -> next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        return prevNode;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL) return true;
        ListNode* slow = head, *fast = head;
        while(fast -> next != NULL and fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *p1 = head, *p2 = reverseLL(slow -> next);
        while(p2 != NULL){
            if(p1 -> val != p2 -> val){
                reverseLL(slow -> next);
                return false;
            }
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        reverseLL(slow -> next);
        return true;
    }
};