class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy;
    ListNode* t = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
    int s = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
    carry = s / 10;
    t = t->next = new ListNode(s % 10);
    if (l1) l1 = l1->next;
    if (l2) l2 = l2->next;
    }
    return dummy.next;
    }
    };