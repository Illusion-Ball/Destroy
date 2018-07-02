/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        ptr->next = list1 ? list1 : list2;
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        int mid = start + (end - start) / 2;
        return mergeTwoLists(mergeKLists(lists, start, mid), mergeKLists(lists, mid + 1, end));
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        return mergeKLists(lists, 0, (int) lists.size() - 1);
    }
};
