class Solution {
    public:
    struct Node { Node* ch[26] = {}; int word = -1; };
    vector<string> res;
    void dfs(vector<vector<char>>& b, int r, int c, Node* n, vector<string>& words) {
    if (r < 0 || c < 0 || r >= (int)b.size() || c >= (int)b[0].size()) return;
    char ch = b[r][c];
    if (ch == '#' || !n->ch[ch - 'a']) return;
    n = n->ch[ch - 'a'];
    if (n->word >= 0) { res.push_back(words[n->word]); n->word = -1; }
    b[r][c] = '#';
    dfs(b, r + 1, c, n, words); dfs(b, r - 1, c, n, words); dfs(b, r, c + 1, n, words); dfs(b, r, c - 1, n, words);
    b[r][c] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Node* root = new Node();
    for (int i = 0; i < (int)words.size(); i++) {
    Node* n = root;
    for (char c : words[i]) { if (!n->ch[c - 'a']) n->ch[c - 'a'] = new Node(); n = n->ch[c - 'a']; }
    n->word = i;
    }
    for (int r = 0; r < (int)board.size(); r++)
    for (int c = 0; c < (int)board[0].size(); c++) dfs(board, r, c, root, words);
    return res;
    }
    };