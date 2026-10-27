class WordDictionary {
    struct Node { Node* ch[26] = {}; bool end = false; };
    Node* root = new Node();
    bool dfs(Node* n, const string& w, int i) {
    if (!n) return false;
    if (i == (int)w.size()) return n->end;
    if (w[i] == '.') { for (auto c : n->ch) if (dfs(c, w, i + 1)) return true; return false; }
    return dfs(n->ch[w[i] - 'a'], w, i + 1);
    }
    public:
    WordDictionary() {}
    void addWord(string word) {
    Node* n = root;
    for (char c : word) { if (!n->ch[c - 'a']) n->ch[c - 'a'] = new Node(); n = n->ch[c - 'a']; }
    n->end = true;
    }
    bool search(string word) { return dfs(root, word, 0); }
    };