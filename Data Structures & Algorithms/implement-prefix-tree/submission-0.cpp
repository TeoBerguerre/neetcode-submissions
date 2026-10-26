class PrefixTree {
    struct TrieNode { TrieNode* ch[26] = {}; bool end = false; };
    TrieNode* root;
    TrieNode* walk(const string& s) {
        TrieNode* n = root;
        for (char c : s) { n = n->ch[c - 'a']; if (!n) return nullptr; }
        return n;
    }
public:
    PrefixTree() : root(new TrieNode()) {}
    void insert(string word) {
        TrieNode* n = root;
        for (char c : word) { if (!n->ch[c - 'a']) n->ch[c - 'a'] = new TrieNode(); n = n->ch[c - 'a']; }
        n->end = true;
    }
    bool search(string word) { TrieNode* n = walk(word); return n && n->end; }
    bool startsWith(string prefix) { return walk(prefix) != nullptr; }
};