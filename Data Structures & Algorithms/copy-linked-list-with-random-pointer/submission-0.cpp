class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        mp[nullptr] = nullptr;
        for (Node* p = head; p; p = p->next) mp[p] = new Node(p->val);
        for (Node* p = head; p; p = p->next) {
            mp[p]->next = mp[p->next];
            mp[p]->random = mp[p->random];
        }
        return mp[head];
    }
};