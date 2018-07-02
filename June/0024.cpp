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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        
        while (prev->next != NULL && prev->next->next != NULL) {
            ListNode* first = prev->next;
            ListNode* second = first->next;
            ListNode* third = second->next;
            
            prev->next = second;
            second->next = first;
            first->next = third;
            
            prev = first;
        }
        return dummy->next;
    }
};
