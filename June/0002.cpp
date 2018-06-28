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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;
        ListNode* head = NULL;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int digit = carry;          
            if (l1 != NULL) {
                digit += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                digit += l2->val;
                l2 = l2->next;
            }
            carry = digit / 10;
            digit %= 10;
            if (head == NULL) {
                head = new ListNode(digit);
                result = head;
            } else {
                head->next = new ListNode(digit);
                head = head->next;
            }
        }
        if (carry) {
            head->next = new ListNode(carry);
        }
        return result;
    }
};
