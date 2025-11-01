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
    int count;
    void recur(ListNode* head, int n){
        if(head == NULL) return;
        // Traverse to the end of the list first.
        recur(head -> next, n);
        // Increment counter as the recursion unwinds.
        // count = 1 for null, 2 for the last node, etc.
        count++;
        // When count reaches n + 1, 'node' is the prev of the target node.
        if(n+1 == count){
            ListNode * toDelete = head -> next;
            head -> next = toDelete -> next;
        }
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        // A temp node allows us to handle edge cases like removing the head.
        ListNode *temp = new ListNode(0); temp -> next = head;
        count = 0;
        recur(temp, n);
        head = temp -> next;
        return temp -> next;
    }
};