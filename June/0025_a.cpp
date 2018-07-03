/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        while (cur != NULL) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        int count = 0;
        ListNode* cur = head;
        ListNode* prev = NULL;
        while (count < k && cur != NULL) {
            prev = cur;
            cur = cur->next;
            count++;
        }
        if (count == k) {
            prev->next = NULL;
            ListNode* newHead = reverseList(head);
            head->next = reverseKGroup(cur, k);
            return newHead;
        }
        return head;
    }
};
