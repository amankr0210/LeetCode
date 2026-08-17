class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode dummy(0);
        ListNode* cur = head;

        while (cur) {
            ListNode* nextNode = cur->next;

            ListNode* pos = &dummy;

            while (pos->next && pos->next->val < cur->val)
                pos = pos->next;

            cur->next = pos->next;
            pos->next = cur;

            cur = nextNode;
        }

        return dummy.next;
    }
};