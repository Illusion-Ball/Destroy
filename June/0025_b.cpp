/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* reverseList(ListNode* first, ListNode* last) {
        ListNode* prev = last;
        while (first != last) {
            ListNode* second = first->next;
            first->next = prev;
            prev = first;
            first = second;
        }
        return prev;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        for (int i = 0; i < k; i++) {
            if (cur == NULL) {
                return head;
            }
            cur = cur->next;
        }
        ListNode* newHead = reverseList(head, cur);
        head->next = reverseKGroup(cur, k);
        return newHead;
    }
};
