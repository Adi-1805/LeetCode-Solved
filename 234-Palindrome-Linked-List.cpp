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
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        ListNode *tortoise = head;
        ListNode *hare = head;
        ListNode *dummy = NULL;
        ListNode *temp = NULL;
        while(hare && hare->next){
            hare = hare->next->next;

            temp = tortoise->next;
            tortoise->next = dummy;
            dummy = tortoise;
            tortoise = temp;
        }
        if(hare && !hare->next) tortoise = tortoise->next;
        while(tortoise){
            if(tortoise->val != dummy->val) return false;

            tortoise = tortoise->next;
            dummy = dummy->next;
        }
        return true;
    }
};