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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* first = head;
        ListNode* second = dummy;
        
        for (int i = 0; i < n - 1; i++) {
            first = first->next;
        }
        while (first->next != NULL) {
            first = first->next;
            second = second->next;
        }
        ListNode *temp = second->next->next;
        delete second->next;
        second->next = temp;
        return dummy->next;
    }
};
