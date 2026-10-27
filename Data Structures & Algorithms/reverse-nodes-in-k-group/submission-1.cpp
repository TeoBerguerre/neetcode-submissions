class Solution {
    public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0, head);
    ListNode* groupPrev = &dummy;
    while (true) {
    ListNode* kth = groupPrev;
    for (int i = 0; i < k && kth; i++) kth = kth->next;
    if (!kth) break;
    ListNode* groupNext = kth->next;
    ListNode *prev = groupNext, *cur = groupPrev->next;
    while (cur != groupNext) { ListNode* nx = cur->next; cur->next = prev; prev = cur; cur = nx; }
    ListNode* first = groupPrev->next;
    groupPrev->next = kth;
    groupPrev = first;
    }
    return dummy.next;
    }
    };