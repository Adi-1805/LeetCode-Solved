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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // (This is my prev failed solution that I corrected)
        // Adding a dummy node at the beginning of the LL to deal with edge case e.g., deleting the head
        ListNode *dummy = new ListNode();
        dummy -> next = head;
        // temp node decalred to facilitate traversal
        ListNode* temp = dummy;
        ListNode *prevToDelete = NULL; // Will try to put this pointer behind the node to be deleted
        int ind = 0; 
        while(ind <= n and temp){
            temp = temp -> next; ind++;
        }
        prevToDelete = dummy;
        // Now the temp and prevToDeleted node have a distance of 'n+1' so when temp reaches end of LL(nullptr) prevToDeleted reaches the node just previous to the node to be deleted
        while(temp != NULL){
            temp = temp -> next; 
            prevToDelete = prevToDelete -> next;
        }
        ListNode *toBeDeleted = prevToDelete -> next;
        prevToDelete -> next = toBeDeleted -> next;

        delete(toBeDeleted);
        return dummy->next;
    }
};