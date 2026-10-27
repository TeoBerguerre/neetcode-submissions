class PrefixTree {
    struct Node { Node* ch[26] = {}; bool end = false; };
    Node* root = new Node();
    Node* walk(const string& s) {
    Node* n = root;
    for (char c : s) { n = n->ch[c - 'a']; if (!n) return nullptr; }
    return n;
    }
    public:
    PrefixTree() {}
    void insert(string word) {
    Node* n = root;
    for (char c : word) { if (!n->ch[c - 'a']) n->ch[c - 'a'] = new Node(); n = n->ch[c - 'a']; }
    n->end = true;
    }
    bool search(string word) { Node* n = walk(word); return n && n->end; }
    bool startsWith(string prefix) { return walk(prefix) != nullptr; }
    };