class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode* pre = &dummy;
        for (int i = 1; i < left; i++) pre = pre->next;
        ListNode* cur = pre->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* nx = cur->next;
            cur->next = nx->next;
            nx->next = pre->next;
            pre->next = nx;
        }
        return dummy.next;
    }
};