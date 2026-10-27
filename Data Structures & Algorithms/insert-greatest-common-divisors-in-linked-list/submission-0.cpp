class Solution {
    public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
    for (ListNode* p = head; p && p->next; p = p->next->next)
    p->next = new ListNode(gcd(p->val, p->next->val), p->next);
    return head;
    }
    };