class Solution {
    public:
    void reorderList(ListNode* head) {
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    ListNode* second = slow->next; slow->next = nullptr;
    ListNode* prev = nullptr;
    while (second) { ListNode* nx = second->next; second->next = prev; prev = second; second = nx; }
    ListNode* first = head;
    while (prev) {
    ListNode *a = first->next, *b = prev->next;
    first->next = prev; prev->next = a;
    first = a; prev = b;
    }
    }
    };