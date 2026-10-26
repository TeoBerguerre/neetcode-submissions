class Solution {
    bool dfs(vector<vector<char>>& b, const string& w, int r, int c, int i) {
        if (i == (int)w.size()) return true;
        if (r < 0 || c < 0 || r >= (int)b.size() || c >= (int)b[0].size() || b[r][c] != w[i]) return false;
        char ch = b[r][c];
        b[r][c] = '#';
        bool found = dfs(b, w, r + 1, c, i + 1) || dfs(b, w, r - 1, c, i + 1) || dfs(b, w, r, c + 1, i + 1) || dfs(b, w, r, c - 1, i + 1);
        b[r][c] = ch;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < (int)board.size(); r++)
            for (int c = 0; c < (int)board[0].size(); c++)
                if (dfs(board, word, r, c, 0)) return true;
        return false;
    }
};