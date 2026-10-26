class Solution {
    public:
    unordered_map<Node*, Node*> seen;
    Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    auto it = seen.find(node);
    if (it != seen.end()) return it->second;
    Node* copy = new Node(node->val);
    seen[node] = copy;
    for (Node* nb : node->neighbors) copy->neighbors.push_back(cloneGraph(nb));
    return copy;
    }
    };