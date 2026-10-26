class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) { ListNode* nx = head->next; head->next = prev; prev = head; head = nx; }
        return prev;
    }
};