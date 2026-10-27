class Solution {
    public:
    Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> m;
    m[nullptr] = nullptr;
    for (Node* p = head; p; p = p->next) m[p] = new Node(p->val);
    for (Node* p = head; p; p = p->next) { m[p]->next = m[p->next]; m[p]->random = m[p->random]; }
    return m[head];
    }
    };