class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        for (ListNode* p = head; p; p = p->next) v.push_back(p);
        int i = 0, j = (int)v.size() - 1;
        while (i < j) {
            v[i]->next = v[j];
            i++;
            if (i == j) break;
            v[j]->next = v[i];
            j--;
        }
        v[i]->next = nullptr;
    }
};